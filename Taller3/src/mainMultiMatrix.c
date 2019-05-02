/*main.c*/

/*
*******************************************************************
				Instituto Tecnológico de Costa Rica
					Ingeniería en Computadores

		Programador: Esteban Agüero Pérez (estape11)
		Lenguaje: C
		Versión: 1.0
		Última Modificación: 10/04/2019

		Entradas:
		Restricciones: Matrices deben ser cuadradas
		Salida:
				Arquitectura de Computadores II
				Prof. Jeferson González Gómez
*******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <smmintrin.h>

// To extract a float from __m128
union vecFloat { 
	__m128 sse; 
	float f[4];
};

/*
 *	Gets a element from Matrix[i,j]
 */
float getIJ(float* matrix, int i, int j, int m){return matrix[i + j*m];}

/*
 *	Sets a element to Matrix[i,j]
 */
void setIJ(float* matrix, int i, int j, int m, float value){matrix[i + j*m] = value;}

/*
 *	Makes the matrix multiplication using SSE
 */
float* multiMatrix4x4(float* matrix1, float* matrix2){
	float* matrixResult = malloc(sizeof(float)*4*4);
	__m128 vecA, vecB, result;
	union vecFloat v;
	int i, j;
	for(i=0;i<4;i++){
		vecA = _mm_setr_ps(getIJ(matrix1,i,0,4),getIJ(matrix1,i,1,4),getIJ(matrix1,i,2,4),getIJ(matrix1,i,3,4));
		for(j=0;j<4;j++){
			vecB = _mm_setr_ps(getIJ(matrix2,0,j,4),getIJ(matrix2,1,j,4),getIJ(matrix2,2,j,4),getIJ(matrix2,3,j,4));
			result = _mm_dp_ps(vecA,vecB,0xFF); // dot product
			v.sse = result;
			setIJ(matrixResult, i, j, 4, v.f[0]); // saves the result
		}

	}
	return matrixResult;
}

int main(int argc, const char* argv[]){
	float* matrix1 = malloc(sizeof(float)*4*4);
	float* matrix2 = malloc(sizeof(float)*4*4);
	float* matrixResult = malloc(sizeof(float)*4*4);
	
	int i,j,k=0;
	// Sets the test matrix1
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			setIJ(matrix1, i, j, 4,(k+1.1));
			k++;
		}
	}
	// Sets the test matrix2
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			setIJ(matrix2, i, j, 4,(k*1.1));
			k++;
		}
	}
	printf("\n> Matrix1\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%f,", getIJ(matrix1, i, j, 4));
			
		}
		printf("\n");
	}

	printf("\n> Matrix2\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%f,", getIJ(matrix2, i, j, 4));
			
		}
		printf("\n");
	}
	
	// execute the operation
	matrixResult = multiMatrix4x4(matrix1,matrix2);

	printf("\n> Result = Matrix1 x Matrix2\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%f,", getIJ(matrixResult, i, j, 4));
			
		}
		printf("\n");
	}

	return 0;
	
}

/*main.c*/