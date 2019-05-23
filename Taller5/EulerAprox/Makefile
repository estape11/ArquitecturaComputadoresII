NVCC = nvcc

all:euler

%.o : %.cu
	$(NVCC) -c $< -o $@

euler : euler.o
	$(NVCC) $^ -o $@

clean:
	rm -rf *.o *.a euler
