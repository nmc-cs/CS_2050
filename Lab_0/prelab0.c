#include <stdio.h>

int countArray(int arr[], int size, int query);

int main(void)
{
    int size = 6;
    int query = 3;
    int arr[] ={1,2,3,4,5,6};
    printf("%d", countArray(arr,size,query)); //printing and calling the function to the console
    return 0;
}

int countArray(int arr[], int size, int query)
{
    int count = 0; //can use any name but variable has to be set to 0 so you can count from 0
    for(int i = 0; i < size; i++)//It is iterating through the array
    {
        if(arr[i] >= query)//Checks each element(array value) to the query value
        {
            count++;//Every time the element is greater than the query value it increases the count by 1
        }
    }
    return count;
}
