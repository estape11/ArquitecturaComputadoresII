#include <stdio.h>
#include <stdlib.h>

/*
	Aqui se defina la funcion que se quiere integrar
*/
double funcion(double x){
	return 4/(1+x*x); // mofificar con la funcion deseada

}

__global__
void aproxIntegral( double (*f)(double), double a, double b , long n, double *result ){
    double suma, tiempoInicio, tiempoEjecucion, resultado;
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if ( i < n ) *result+=(*f)(a+i*(b-a)/n);    

}

int main(){
    int N = 10;
    int nblocks = (N+255) / 256;
    double a;
    aproxIntegral<<<nblocks, 256>>>(funcion, 0, 1, N, &a);

    printf("> Result %lf", a );

    return 0;

}
