#include "pl5.h"

List * initList(int *ec)
{
    List *arr;
    if(!(arr = malloc(sizeof(List))))
    {
        return NULL;
    }
    else
    {
        arr->object = 0;
        arr->next = NULL;
        ec = 0;
        return arr;
    }
}

List * insertAtHead(int val, List *head, int *ec)
{
    List *p;
    p = malloc(sizeof(List));
    if(p)
    {
        p->object = val;
        p->next = head;
        ec = 0;
    }
    return p;
}

int getAtIndex(int index, List *head)
{
    List *temp = head;
    for(int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    return(temp->object);
}

int getListLength(List *head)
{
    List *temp = head;
    int count = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

List *freeList(List* head)
{
    free(head);
    return NULL;
}
