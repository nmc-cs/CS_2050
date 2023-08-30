#include <stdio.h>

void getArrayInfo(int *array, int n, int *min, int *max, int *dval);// int n is size of array, dval is distinct value

int main(void)
{
    int n = 10;//array size
    int min,max,dval;
    int arr[] = {9,3,9,5,1,3,2,7,6,3}; //array numbers
    //int arr[]={1,3,3,3,3,3,3,3,3,3};
    getArrayInfo(arr, n, &min, &max, &dval);
    printf("Min Val:%d\nMax Val:%d\n",min, max);
    printf("Distinct Values:%d\n", dval);
    return 0;
}

void getArrayInfo(int *array, int n, int *min, int *max, int *dval)
{
    int count = 1;
    *min = *max = array[0];
    for(int i = 1; i < n; i++)
    {
        if(array[i] < *min)
        {
            *min = array[i];
        }

        if(array[i] > *max)
        {
            *max = array[i];
        }
    }

    for(int i = 1; i < n; i++)
    {
        int j = 0;
        for( j = 0; j < n; j++)
        {
        //printf("array:%d = %d, array:%d = %d,\n", i,array[i], j, array[j]);
            if(array[i] == array[j])
            {
                break;
            }
        }
        if(i == j)
        {
            count++;
        }
    }
    *dval = count;
}
