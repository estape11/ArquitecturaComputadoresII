/*
*******************************************************************
				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores
		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C
		Versión: 1.0
		Última Modificación: 26/04/2019
		Entradas: Cantidad de elementos
		Restricciones: Deber ser números
		Salidas: Tiempo tomado en realizar SAXPY
				Arquitectura de Computadores II
				Prof. Jeferson González Gómez
*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc > 1){
		int N = atoi(argv[1]);
		int16_t* x;
		int16_t* y;

		x= (int16_t*)malloc(N * sizeof(int16_t));
		memset(x,2,N*sizeof(int16_t));

		y= (int16_t*)malloc(N * sizeof(int16_t));
		memset(y,5,N*sizeof(int16_t));

		double start_time, run_time;
		int16_t a = 11;
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