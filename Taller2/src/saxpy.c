#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
	if(argc > 1){
		int N = atoi(argv[1]);
		float* x;
		float* y;

		x= (float*)malloc(N * sizeof(float));
		y= (float*)malloc(N * sizeof(float));

		double start_time, run_time;
		float a = 2.718281;
		int i;

		start_time = omp_get_wtime();

	  	for ( i = 0; i < N; ++i){
	  		y[i] = a*x[i] + y[i];
		}
		
		run_time = omp_get_wtime() - start_time;
		
		printf("Tiempo tomado: %fs\n",run_time);

		free(x);
		free(y);
	}	
	return 0;
}