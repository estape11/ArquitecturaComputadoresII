************************************************************

	Instituto Tecnológico de Costa Rica
	Ingeniería en Computadores

	Programador: Esteban Agüero Pérez (estape11)

	Última Modificación: 26/02/2019

	Arquitectura de Computadores II
	Prof. Jeferson González Gómez

************************************************************

> Para la compilacion:
		cd src
		make X
	* X puede ser pi, pi_par, saxpy, saxpy_par o IntegralesAproximacion
	
> Si se desea eliminar compilados:
		make clean

> Para ejecutar:
	> Saxpy:
		./saxpy X
		./saxpy_par X Y
		* X cantidad de elementos y Y cantidad de hilos
	> IntegralesAproximacion:
		./IntegralesAproximacion -flags
			-a valor de limite inferior
			-b valor de limite superior
			-n numero de iteraciones
			-t numero de hilos
		* Si se desea aproximar otra funcion se debe modificar la funcion
		"funcion(x)" con la deseada y recompilar