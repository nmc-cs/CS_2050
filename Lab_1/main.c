//#include "lab1.h"
#include <stdio.h>
#include <stdlib.h>

int getAverage(int array[], int size, float *result);
int sumEven(int array[], int size, float *result);

int main(void)
{
    int size = 5; //size of array
    //nt avg;
    float result;
    int arr[] = {5,5,5,5,5};
    getAverage(arr, size, &result);
    printf("Average of array: %0.2f\n", result);
    sumEven(arr, size, &result);
    printf("Total of even numbers: %0.2f\n", result);
    return 0;
}
