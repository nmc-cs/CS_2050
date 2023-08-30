
#include "lab0.h"

int countOccurrences(int size, int arr[], int query)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == query)
        {
            count++;
        }
    }
    return count;
}
