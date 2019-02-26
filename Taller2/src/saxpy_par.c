#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
	if(argc > 2){
		int N = atoi(argv[1]), hilos = atoi(argv[2]);
		float* x;
		float* y;

		x= (float*)malloc(N * sizeof(float));
		y= (float*)malloc(N * sizeof(float));

		double start_time, run_time;
		float a = 2.718281;
		int i;

		omp_set_num_threads(hilos);
		start_time = omp_get_wtime();
		
		#pragma omp parallel
		{
			#pragma omp for private(i)
		  	for ( i = 0; i < N; ++i){
				y[i] = a*x[i] + y[i];
			}
		}

		run_time = omp_get_wtime() - start_time;
		printf("Tiempo tomado: %fs, con %i hilos\n",run_time, hilos);
		
		free(x);
		free(y);

	}
	return 0;
}