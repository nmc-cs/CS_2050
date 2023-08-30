#include "lab2.h"

int makeArray(int **array, int size);
void initArray(int *array, int size);
int multiplyEven(int *array, int size, int multiplicand);
void freeArray(int **array);

int main(void)
{
    int * array;
    int size = 10;
    int multiplicand = 3;

    makeArray(&array, size);
    initArray(array, size);
    printf("\n");
    multiplyEven(array, size, multiplicand);
    freeArray(&array);


    return 0;
}
