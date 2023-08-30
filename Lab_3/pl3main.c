#include "prelab3.h"

int main(void)
{
    int length = 9;
    int dataTypeSize = 4;
    void *result = createArray(length,dataTypeSize);
    printf("%p\n", result);
    printf("%d\n", getArraySize(result));
    freeArray(result);
    printf("%p\n", result);

    return 0;
}
