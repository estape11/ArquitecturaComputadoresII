/*
*******************************************************************
				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores
		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C
		Versión: 1.0
		Última Modificación: 26/04/2019
		Entradas: Cantidad de elementos e hilos
		Restricciones: Deber ser números
		Salidas: Tiempo tomado en realizar SAXPY paralelo
				Arquitectura de Computadores II
				Prof. Jeferson González Gómez
*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <arm_neon.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc > 2){
		int N = atoi(argv[1]), hilos = atoi(argv[2]);
		int16_t* x;
		int16_t* y;

		x= (int16_t*)malloc(N * sizeof(int16_t));
		memset(x,2,N*sizeof(int16_t));

		y= (int16_t*)malloc(N * sizeof(int16_t));
		memset(y,5,N*sizeof(int16_t));

		double start_time, run_time;
		int16_t a[4] = {11, 11, 11, 11};

		int16x4_t aVect = vld1_s16(a);
		int i;

		omp_set_num_threads(hilos);
		//int size = N;
		assert((N % 4) == 0);
		start_time = omp_get_wtime();
		
		#pragma omp parallel
		{
			#pragma omp for private(i)
		  	for ( i = 0; i < N; i+=4){
		  		// Loads the vectors
				int16x4_t xTemp = vld1_s16((x+i));
				int16x4_t yTemp = vld1_s16((y+i));

				// a*x[i]
				int16x4_t resul1 = vmul_s16(aVect,xTemp);

				// a*x[i] + y[i];
				int16x4_t resul2 = vadd_s16(resul1,yTemp);

				//y[i] = a*x[i] + y[i];
				y[i] = vget_lane_s16(resul2, 0);
				y[i+1] = vget_lane_s16(resul2, 1);
				y[i+2] = vget_lane_s16(resul2, 2);
				y[i+3] = vget_lane_s16(resul2, 3);

			}
		}

		run_time = omp_get_wtime() - start_time;
		printf("Tiempo tomado: %fs, con %i hilos\n",run_time, hilos);
		free(x);
		free(y);

	}
	return 0;
}
