/*
*******************************************************************
				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores
		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C++
		Versión: 1.0
		Última Modificación: 02/05/2019
		Entradas: funcion y limites 
		Restricciones: Deber ser un número
		Salidas: Tiempo tomado
				Arquitectura de Computadores II
				Prof. Jeferson González Gómez
*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

/*
	Definicion de las funciones
*/

double aproxIntegral ( double (*f)(double), double ,double, long);

double aproxIntegralPara ( double (*f)(double), double ,double, long, int);

double funcion(double);

int main(int argc, char* argv[]){
	double a, b;
	long n;
	char bandera;
	int hilos;

	a = 0; b = 1; // limites de la integral por defecto
	n = 100000000; // valor maximo de iteraciones por defecto
	hilos = omp_get_num_procs();// cantidad de hilos por defecto

	// parseo de los argumentos
	printf("Valores: a=%lf, b=%lf, n=%ld \n",a,b,n );
	printf("> Realizando el calculo...\n");
	aproxIntegral(funcion, a, b, n);
	aproxIntegralPara(funcion, a, b, n, hilos);

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

	printf("\nTiempo Serie tomado: %fs\n",tiempoEjecucion);

	resultado = ( (b-a)/n )*( ( (*f)(a) + (*f)(b) )/2 + suma );
	printf(">> Resultado: %lf\n", resultado);

	return resultado;
}

double aproxIntegralPara ( double (*f)(double), double a, double b , long n, int hilos){
	long k;
	double suma, tiempoInicio, tiempoEjecucion, resultado;

	omp_set_num_threads(hilos);
	tiempoInicio = omp_get_wtime();

	#pragma omp parallel
	{
		#pragma omp for reduction(+:suma) private(k)
	  	for(k=1 ; k<n ; k++){
	  		suma+=(*f)(a+k*(b-a)/n);

	  	}
	}

	tiempoEjecucion = omp_get_wtime() - tiempoInicio;
	printf("\nTiempo Paralelo tomado: %fs, con %i hilos\n",tiempoEjecucion, hilos);

	resultado = ( (b-a)/n )*( ( (*f)(a) + (*f)(b) )/2 + suma );
	printf(">> Resultado: %lf\n", resultado);
	
	return resultado;
}

/*
	Aqui se defina la funcion que se quiere integrar
*/
double funcion(double x){
	return 4/(1+x*x); // mofificar con la funcion deseada

}
