#include <stdio.h>

int getAverage(int array[], int size, float *result)
{
    int total = 0;
    int avg;
    for(int i = 0; i < size; i++) //iterates through the array
    {
        total = total + array[i]; //calculates the total of the numbers in array
    }
    avg = total / size; //divides total by the amount of numbers in array
    *result = avg; // sets equal avg to pointer result

    if(avg == *result) //if it equals the pointers result value then it should return success and if not it shoudl return failure
    {
        printf("Success: 0\n");
    }
    else
    {
        printf("Failure: 1\n");
    }
    return avg;
}

int sumEven(int array[], int size, float *result)
{
    int total;
    for(int i = 0; i < size; i++) //iterates through the array
    {
        if(array[i]%2 == 0)// selects the even numbers in the array which in this case are none
        {
            total = total + array[i]; // totals the even numbers in the array
        }
    }
    total = *result; //sets total equal to pointer result
    if(total == *result)// if the total value does not equal the pointer result then it should print out failure otherwise success
    {
        printf("Failure: 1\n");
    }
    else
    {
        printf("Success: 0\n");
    }
    return total;
}
