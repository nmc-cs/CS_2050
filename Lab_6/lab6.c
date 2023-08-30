#include "lab6.h"

int makeList(Node **list)
{
    Node *dummyNode = malloc(sizeof(Node)); //Makes a dummy node allocates memory to it and it will return 0 and 1 if intitialziation was successful or not.
    if(dummyNode == NULL)
    {
        return 1;
    }
    dummyNode->next = NULL;
    dummyNode->data = NULL;
    *list = dummyNode;
    return 0;
}

//
int getSize(Node *list) //gets the size of the list elements
{
    Node *temp = list->next; //takes the list *temp and sets it to head;
    int count = 0; //sets count to zero

    while(temp != NULL) //loops through the list
    {
        temp = temp->next;
        count++; //incrememnts count
    }
    return count; //return count depepnding on amount of increments count++ did
}

//void *getAtIndex(Node *list, int index)
//{

//}

//It takes a pointer t and allocates memory to it goes through an if statement
//and if it is equal to NULL it returns 1 on failure
// pointer t points to next and sets it to null sets to data to data
//crea
int insertAtTail(Node *list, void *data)
{
    Node *t = malloc(sizeof(Node));
    if(t == NULL)
    {
        return 1;
    }

        t->next = NULL;
        t->data = data;
        Node *present = t;
        while(present->next != NULL)
        {
            present = present->next;
        }
        present->next = t;
        return 0;
}

void * removeFromHead(Node *list)
{
   void *data = NULL;
   if(list->next == NULL)
   {
    return NULL;
   }
   Node *head = list->next;
   data = head->data;
   list->next = head->next;
   free(head);
   return data;
}

void freeList(Node **list)
{
    Node *temp = *list;
    while(temp != NULL)
    {
        free(temp);
        temp = temp->next;
    }
    *list = NULL;
}
