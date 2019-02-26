#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main(int argc, char *argv[]){
	float* x;
	float* y;

	x= (float*)malloc(N * sizeof(float));
	y= (float*)malloc(N * sizeof(float));

	double start_time, run_time;
	float a = 2.718281;
	int i,n;

	for(n=1;n<30;n++){
		omp_set_num_threads(n);
		start_time = omp_get_wtime();
		#pragma omp parallel
		{
			#pragma omp for default(none) private(i) shared(a, N, x,y)
		  	for ( i = 0; i < N; ++i){
				y[i] = a*x[i] + y[i];
			}
		}

		run_time = omp_get_wtime() - start_time;
		printf("Tiempo tomado: %f s\n",run_time);
	}
	
	

	free(x);
	free(y);
	
	return 0;
}