#include "prelab3.h"

void * createArray(int length, int dataTypeSize)
{
    int *array;
    array = malloc(length * dataTypeSize + sizeof(int));
    array[0] = length;

    return (void*)(array + 1);
}

int getArraySize(void *array)
{
    return ((int*)array)[-1];
}

void freeArray(void *arr)
{
    int *array = arr;
    array--;
    free(array);
    array = NULL;
}
