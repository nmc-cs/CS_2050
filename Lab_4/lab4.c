#include "lab4.h"

void * makeArray(int arraySize , int elementSize)
{
    int *arr;

    arr = malloc(arraySize *sizeof(elementSize)+ sizeof(int));

    if(arr == NULL)
    {
        return NULL;
    }
    else
    {
        return(void*)(arr + 1);
    }
}

int getSize(void *array)
{
    return ((int*)array)[-1];
}

int countWithWeight(InventoryItem *items , float weight)
{
    int obj = 0;
    for(int i = 0; i < getSize(items); i++)
    {
        if(items[i].weight == weight)
        {
            obj++;
        }
    }
    return obj;
}

void freeArray(void *array)
{
    int *arr = array;
    arr--;
    free(arr);
    array = NULL:
}
