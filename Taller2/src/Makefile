all: saxpy saxpy_par

saxpy_par.o:saxpy_par.c

saxpy_par:saxpy_par.o
		gcc -o saxpy_par saxpy_par.o -fopenmp

saxpy.o:saxpy.c

saxpy:saxpy.o
		gcc -o saxpy saxpy.o -fopenmp

clean:
		rm -f *.o
		rm -f *.so
		rm -f *.a
		rm -f saxpy
		rm -f pi_par
		rm -f saxpy_par
		rm -f pi

.PHONY: clean
