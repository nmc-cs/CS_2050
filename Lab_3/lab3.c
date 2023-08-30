#include "lab3.h"

char * strAlloc(int size) //allocates memory for char
{

    char *arr; //makes a char arr pointer
    arr = malloc(size * sizeof(char)); //allocateds memory using mallic to char
    arr[0] = size; //sets arr equal to size

    if(arr == NULL) //if the arr is failure it returs null
    {
        return NULL; //returns null
    }
    else
    {
        return(char*)(arr + 1); //returns pointer to the array
    }
}

int strLen(char *str) //
{
    char *tString = (char*)str; //creates a temp string and sets it equal to char pointer
    --tString;
    return tString[0]; //returns the size stored previously
}

void strCpy(char *source, char *dest)// will take source array contents and put into dest
{
    int length = strLen(source); //sets length to strlen(source)
    for(int i = 0; i < length; i++)//iterates through the length
    {
        dest[i] = source[i]; //sets dest equals to sourcce of i
    }
}
int strCmp(char *source, char *dest)//compares both source and dest
{
    int length = strLen(source);
    int count = 0; //sets count to zero

    for(int i = 0; i < length; i++) //iterates through the length
    {
        if(source[i]==dest[i]) //adds to count if source == dest
        {
            count++;
        }
    }
    if(count == length)// if the count == length it will return 1
    {
        return 1;
    }
    else
    {
        return 0; //otherwise it will return 0 if they are not the same string
    }
}

void strFree(char *str) //frees the memory
{
    char *array = str; //takes the *array and sets it to str
    array--;
    free(array); //frees array
    array = NULL;//sets array to null
}
