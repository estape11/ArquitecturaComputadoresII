/*main.c*/

/*
*******************************************************************
				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores

		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C
		Versión: 1.0
		Última Modificación: 10/04/2019

		Entradas: 2 vectores de 8 shorts 
		Restricciones: deben ser shorts
		Salida: el vector del mayor valor de cada posicion
				Arquitectura de Computadores II
				Prof. Jeferson González Gómez
*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emmintrin.h>

/*
 *	Receives a char* array and returns parsed to short*
 */
short* parseArray(const char* array, int size) {
    char* arrayCopy = malloc(strlen(array) + 1);
    char* splitedArray = malloc(strlen(array) + 1);
    short* arrayShort = malloc(sizeof(short)*size);
    strcpy(splitedArray, array); // copy of array
    char* temp;
    int i;
    for(i=0 ; i<size ; i++){
    	strcpy(arrayCopy, splitedArray); // to move the cursor 
    	temp = strchr(arrayCopy,',');
    	strtok(arrayCopy, ",");

    	if(temp != NULL){
    		arrayShort[i] = (short) atoi(arrayCopy);
    		splitedArray = strchr(splitedArray,','); // remove the recent number
    		splitedArray++; // to remove the comma

    	} else{
    		arrayShort[i] = (short) atoi(arrayCopy);

    	}  
    	  	
    }

    return arrayShort;
}


int main(int argc, const char* argv[]){
	if(argc == 3) { // MaxColums arrayA arrayB
		printf("\tVector 1   > [%s]\n", argv[1]);
		printf("\tVector 2   > [%s]\n", argv[2]);
		short* array1 = parseArray(argv[1],8);
		short* array2 = parseArray(argv[2],8);

		__m128i vecA = _mm_set_epi16(array1[0],array1[1],array1[2],array1[3],array1[4],array1[5],array1[6],array1[7]);
		__m128i vecB = _mm_set_epi16(array2[0],array2[1],array2[2],array2[3],array2[4],array2[5],array2[6],array2[7]);
		__m128i result = _mm_max_epi16 (vecA, vecB);

		// Extracts the result
		printf("\tMax Vector > [");
		printf("%d,", _mm_extract_epi16(result,7) );
		printf("%d,", _mm_extract_epi16(result,6) );
		printf("%d,", _mm_extract_epi16(result,5) );
		printf("%d,", _mm_extract_epi16(result,4) );
		printf("%d,", _mm_extract_epi16(result,3) );
		printf("%d,", _mm_extract_epi16(result,2) );
		printf("%d,", _mm_extract_epi16(result,1) );
		printf("%d", _mm_extract_epi16(result,0) );
		printf("]\n");

	} else{
		printf(">> Example of execution: \n");
		printf("\t ./MaxColumn 1,2,3,4,5,6,7,8 8,7,6,5,4,3,2,1\n");
		return -1;

	}
	
	return 0;
}



/*main.c*/