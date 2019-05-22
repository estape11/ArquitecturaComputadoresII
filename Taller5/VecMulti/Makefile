NVCC = nvcc

all: vecmulti

%.o : %.cu
	$(NVCC) -c $< -o $@

vecmulti : vecmulti.o
	$(NVCC) $^ -o $@

clean:
	rm -rf *.o *.a vecmulti
