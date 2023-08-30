#include "lab3.h"

int main(void)
{
    int size = 15;
    int size1 = 18;

    char *source = strAlloc(size);
    char *dest = strAlloc(size1);
    printf("Length of source: %d\n", strLen(source));
    printf("Length of dest: %d\n", strLen(dest));

    source[1] = 'a';
    source[2] = 'b';

    strCpy(source, dest);
    printf("The result of the comparison is: %d\n", strcmp(source, dest));

    strFree(source);
    strFree(dest);

    return 0;
}
