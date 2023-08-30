#include "lab9.h"

void * makeArray(int arraySize, int elementSize)
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

int searchClients(Client *array, Client *query)
{
   return binaryHelp(array, query, 0, getSize(array)-1);
}

int binaryHelp(Client *array, Client *query, int low, int high) //I put this in the header file for the code to work
{
    // 
    if(low > high) //chekcs if the lower value is bigger than the high value
    {
        return -1;
    }
    int mid = (high + low) / 2;
    if(compareClients(&array[mid], query) == 0)
    {
        return mid;
    }
    else if(compareClients(&array[mid], query) < 0)
    {
        return binaryHelp(array, query, mid+1, high);
    }
    else{
        return binaryHelp(array, query, low, mid-1);
    }
}
int compareClients(Client *a, Client *b) //takes in the Client parameters of a and b and compares them
{
    if(a->accountWorth < b->accountWorth)
    {
        return -1;
    }
    else if(a->accountWorth > b->accountWorth)
    {
        return 1;
    }
    else{
        return 0;
    }

    // void *ptr = makeArray(10, sizeof(Client));
    // if(ptr == NULL)
    // {
    //     return 1; //handle allocation failure
    // }

    // Client* clients = (Client*)ptr;
    // for(int i = 0; i < n; i++)
    // {
    //     clients[i].accountNumber = i;
    //     clients[i].accountNumber = (n-i);


    // }
}

void freeArray(void *array) //free the memory that was used and sets it to NULL
{
   free(((int*)array)-1);
   array = NULL;
}
