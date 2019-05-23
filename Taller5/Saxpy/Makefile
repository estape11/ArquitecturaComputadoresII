NVCC = nvcc

all: vecsaxpy

%.o : %.cu
	$(NVCC) -c $< -o $@

vecsaxpy : vecsaxpy.o
	$(NVCC) $^ -o $@

clean:
	rm -rf *.o *.a vecsaxpy
