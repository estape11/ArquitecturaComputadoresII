/*
*******************************************************************

				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores

		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C++
		Versión: 1.0
		Última Modificación: 26/02/2019

		Entradas: funcion y limites 
		Restricciones: Deber ser un número
		Salidas: Tiempo tomado en realizar SAXPY serie

				Arquitectura de Computadores II
				Prof. Jeferson González Gómez

*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double aproxIntegral ( double (*f)(double), double ,double, long);

double aproxIntegralPara ( double (*f)(double), double ,double, long);

double funcion(double);

int main(){
	int a, b;
	double n;

	a = 0; b = 1; // limites de la integral
	n = 100000000; // valor maximo de iteraciones

	printf("> Realizando el calculo...\n");
	aproxIntegral(funcion, a, b, n);
	aproxIntegralPara(funcion, a, b, n);

	return 0;

}


double aproxIntegral ( double (*f)(double), double a, double b , long n){
	long k;
	double suma, tiempoInicio, tiempoEjecucion, resultado;

	tiempoInicio = omp_get_wtime();

	for(k=1 ; k<n ; k++){
		suma+=(*f)(a+k*(b-a)/n);

	}

	tiempoEjecucion = omp_get_wtime() - tiempoInicio;

	printf("Tiempo Serie tomado: %fs\n",tiempoEjecucion);

	resultado = ( (b-a)/n )*( ( (*f)(a) + (*f)(b) )/2 + suma );
	printf(">> Resultado: %lf\n", resultado);
	return resultado;
}

double aproxIntegralPara ( double (*f)(double), double a, double b , long n){
	long k;
	double suma, tiempoInicio, tiempoEjecucion, resultado;

	//omp_set_num_threads(2);
	tiempoInicio = omp_get_wtime();

	#pragma omp parallel
	{
		#pragma omp for reduction(+:suma) private(k)
	  	for(k=1 ; k<n ; k++){
	  		suma+=(*f)(a+k*(b-a)/n);

	  	}
	}


	tiempoEjecucion = omp_get_wtime() - tiempoInicio;
	printf("Tiempo Paralelo tomado: %fs, con %i hilos\n",tiempoEjecucion, 2);

	resultado = ( (b-a)/n )*( ( (*f)(a) + (*f)(b) )/2 + suma );
	printf(">> Resultado: %lf\n", resultado);
	return resultado;
}

/*
	Aqui se defina la funcion que se quiere integrar
*/
double funcion(double x){
	return 4/(1+x*x);

}