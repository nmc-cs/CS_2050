#include "lab5.h"

int makeList(Node **list)//makes an empty list that alwasy return zero
{
   *list = NULL; //intializes Node* to empty list
   return 0; //Will always return 0
}

int getSize(Node *list) //gets the size of the list elements
{
    Node *temp = list; //takes the list *temp and sets it to head;
    int count = 0; //sets count to zero

    while(temp != NULL) //loops through the list
    {
        temp = temp->next;
        count++; //incrememnts count
    }
    //printf("count = %d\n", count);
    return count; //return count depepnding on amount of increments count++ did
}

int insertAtHead(Node **list, void *data) //takes the pointer and inserts to the h(head) list
{
    Node *h = malloc(sizeof(Node)); //allocates memory for list head;
    if(h)
    {
        h->data = data; //insert head to data and equal data
        h->data = h; //insert head to data and equal head
        *list = h; //sets *list to head;
        return 0;//success
    }
    return 1; //faiklure
}

void * removeFromTail(Node **list)//removes elelment at tail of the list if there are any to be removed
{
    if(*list == NULL)//if pointer list empty
    {
        return NULL; //it will return NULL;
    }
    if((*list)->next == NULL)
    {
        void *data = (*list)->data;
        free(*list); //frees the memory from *list
        *list = NULL; //clears memory by setting it to NULL
        return data; //returns data removed from the list
    }
    Node * start = *list;
    while(start->next->next != NULL)
    {
        start = start->next;
    }
    void *data = start->next->data;
    free(start->next);
    start->next = NULL;
    return data; //returns data removed from the list
}

void freeList(Node **list) //frees the memory allocated to the list
{
    Node *temp = *list;
    while(temp != NULL)//if temp is not equal to NULL
    {
        free(temp); //we free memory for tempsince temp is = to list
        temp = temp->next; //insert temp to next
    }
    *list = NULL; //set pointer list to null
}
