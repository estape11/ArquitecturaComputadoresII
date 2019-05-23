#include <iostream>
#include <stdio.h>
#include <math.h>

__global__
void logX(float x, int N, double *result) {
    long i = blockDim.x * blockIdx.x + threadIdx.x;
    if ( i < N ) {
        *result += pow(x, i) / factorial(i);

    }
}

int main() {
    std::cout<<"> Started "<<std::endl;
    return 0;

}

