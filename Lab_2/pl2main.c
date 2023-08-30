#include "prelab2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length);

int main(void)
{
    FILE *fptr;
    fptr = fopen("file.txt", "r");
    int length;
    float *a;

    a = readFloatFileIntoArray(fptr, &length);
    printf("Values: %f\n", *a);
    freeFloatArray(**fptr);

    //freeFloatArray(**fptr);


    fclose(fptr);
    return 0;
}
