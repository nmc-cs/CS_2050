#include "pl5.h"

int main(void)
{
    List *head;
    int ec;
    head = initList(&ec);

    for(int i = 1; i < 100; i++)
    {
        head = insertAtHead(i, head, &ec);
    }

    //Test case printing out values
    List *temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->object);
        temp = temp->next;
    }

    //Test case getting values at the index
    int res = getAtIndex(3, head);
    printf("\n%d\n", res);

    int length = getListLength(head);
    printf("Length: %d", length);

    freeList(head);

    return 0;
}
