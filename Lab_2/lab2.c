#include "lab2.h"

int makeArray(int **array, int size)
{
    int *arr; //pointer to set equal to malloc

    arr = malloc(size*sizeof(int));//allocates memory of type int
    if(arr == NULL)// chekcing if memory is not null
    {
        return 1; //failure
    }
    else
    {
        *array = arr;//setting *arr to *array in the function prototype
        return 0;//success
    }
}

void initArray(int *array, int size)
{

    for(int i = 0; i < size; i++)//iterates through the data set
    {
        array[i] = 0; //sets all the data values to 0

    }
}

int multiplyEven(int *array, int size, int multiplicand)
{
    int count = 0; //creats a count variable and sets it to 0

    for(int i = 0; i < size; i++)//iterates throught the array
    {
       if(i%2 == 0)//selelcts all even numbers
       {
            array[i] = (array[i] * multiplicand);//formulat to multiply all even numbers
            count ++; //to keep track of amount of tiems multiplied
       }
    }
    return count;
}

void freeArray(int **array)
{
    free(*array);//frees array values
    *array = NULL;//sets to null to reset
}
