#include "prelab2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length)
{
    float *a;
    int n;

    fscanf(fptr, "%d", &n);

    a = malloc(n*sizeof(float));
    if(a == NULL)
    {
        printf("Failure\n");
        return 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            fscanf(fptr, "%f", &a[i]);
            printf("%f\n", a[i]);
        }
        *length = n;
        return a;
    }

}

void freeFloatArray(float **fptr)
{
    free(*fptr);
    *fptr = NULL;
}
 