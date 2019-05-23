NVCC = nvcc

all:integrals

%.o : %.cu
	$(NVCC) -c $< -o $@

integrals : integrals.o
	$(NVCC) $^ -o $@

clean:
	rm -rf *.o *.a integrals
