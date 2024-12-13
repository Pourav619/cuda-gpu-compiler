#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void sampleKernel(int* data) {
    int idx = threadIdx.x;
    data[idx] *= 2;
}

int main() {
    const int arraySize = 10;
    int hostArray[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* deviceArray;

    cudaMalloc(&deviceArray, arraySize * sizeof(int));
    cudaMemcpy(deviceArray, hostArray, arraySize * sizeof(int), cudaMemcpyHostToDevice);

    sampleKernel<<<1, arraySize>>>(deviceArray);

    cudaMemcpy(hostArray, deviceArray, arraySize * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(deviceArray);

    std::cout << "Processed data:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << hostArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
