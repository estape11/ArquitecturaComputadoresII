#************************************************************
#
#	Instituto Tecnológico de Costa Rica
#	Ingeniería en Computadores
#
#	Programador: Esteban Agüero Pérez (estape11)
#
#	Última Modificación: 02/04/2019
#
#	Arquitectura de Computadores II
#	Prof. Jeferson González Gómez
#
#************************************************************

APP=MaxColumn
APP1=MultiMatrix
CC=gcc
LIBS=../lib
INCLUDE=../include
LINKERFLAGS=-msse -msse2 -mssse3 -msse4
OUT=../bin

all: setup $(APP) $(APP1) hello_simd 

setup:
		mkdir -p $(OUT)

$(APP):main$(APP).c setup
		$(CC) main$(APP).c -o $(OUT)/$(APP) $(LINKERFLAGS)

$(APP1):main$(APP1).c setup
		$(CC) main$(APP1).c -o $(OUT)/$(APP1) $(LINKERFLAGS)

hello_simd:hello_simd.c setup
		$(CC) hello_simd.c -o $(OUT)/hello_simd $(LINKERFLAGS)

clean:
		rm -rf  $(OUT)
		rm -f *.o 
		rm -f *.so
		rm -f *.a

.PHONY:clean setup
