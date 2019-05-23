#include <stdio.h>
#include <stdexcept>
#include <algorithm>
#include <cuda_runtime.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void saxpySerial(int n, float alpha, float *x, float *y) {
    for ( int i = 0 ; i<n ; ++i ){
        y[i] = alpha*x[i] + y[i];

    }

}

__global__
void saxpyParallel(int n, float alpha, float *x, float *y) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if ( i<n ) y[i] = alpha*x[i] + y[i];

}

int main(int argc, char* argv[]){
    std::cout<< "> Starting "<<std::endl;
    
    float *x, *y, *d_x, *d_y;

    int N = 10;

    if (argc>1) {
        N = atoi(argv[1]);
    }
    std::cout<<"> N = "<<N<<std::endl;
    x = (float *) malloc(N*sizeof(float));
    y = (float *) malloc(N*sizeof(float));

    cudaMalloc(&d_x, N*sizeof(float));
    cudaMalloc(&d_y, N*sizeof(float));

    for (int i = 0 ; i<N ; i++){
        x[i]=3.0;
        y[i]=4.0;

    }
    
    cudaMemcpy(d_x, x, N*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, N*sizeof(float), cudaMemcpyHostToDevice);

    int nblocks = (N+255) / 256;
    clock_t tiempoInicio, tiempoFinal;
    double resultado;

    tiempoInicio = clock();

    saxpyParallel<<<nblocks, 256>>>(N, 2.0f, d_x, d_y);
    
    tiempoFinal = clock();

    resultado = (double) (tiempoFinal-tiempoInicio)/ CLOCKS_PER_SEC;
	printf("> Total time Paralell: %lf s\n", resultado);
    
    tiempoInicio = clock();
    saxpySerial(N, 2.0, x, y);
    tiempoFinal = clock();


    std::cout<< "> Finished <"<<std::endl;
    resultado = (double) (tiempoFinal-tiempoInicio)/ CLOCKS_PER_SEC;
    printf("> Total time Serial: %lf s\n", resultado);

    cudaFree(d_x);
    cudaFree(d_y);
    
    free(x);
    free(y);

    return 0;

}
