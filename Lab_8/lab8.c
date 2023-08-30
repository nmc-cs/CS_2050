#include "lab8.h"

struct _Node
{
    struct _Node *next;
    int priority;
    void *data;
}typedef Node;

typedef struct Info
{
    int ec;
    int size;
    Node *head;
}Info;

int pqGetErrorCode(PQueue q)
{
    if(q.info == NULL)
    {
        return 1;
    }
    else
    {
        return (q.info)->ec;
    }
}

PQueue pqInit()
{
    PQueue q;
    q.info = malloc(sizeof(Info));
    if(q.info == NULL)
    {
        q.info->ec = 1;
        return q;
    }

    q.info->ec = 0;
    q.info->size = 0;
    q.info->head = NULL;

    return q;
}

int pqInsert(void *data, int priority, PQueue q)
{
    Node *tmp = malloc(sizeof(Node));
    if(tmp == NULL)
    {
        q.info->ec = 1;
        return((q.info)->ec);
    }
    tmp->data = data;
    tmp->priority = priority;
    if(q.info->head == NULL || priority > q.info->head->priority)
    {
        tmp->next = q.info->head;
        q.info->head = tmp;
        q.info->size++;
        q.info->ec = 0;
        return ((q.info)->ec);
    }
    else{
        Node *current = q.info->head;
        while(current->next != NULL && priority < current->next->priority)
        {
            current = current->next;
        }
        tmp->next = current->next;
        current->next = tmp;
    }
    q.info->size++;
    q.info->ec = 0;
    return ((q.info)->ec);
}

void * pqRemoveMax(PQueue q)
{
    if(q.info->head == NULL)
    {
        q.info->ec = 2;
        return NULL;
    }
    void *data = q.info->head->data;
    Node *tmp = q.info->head->next;
    free(q.info->head);
    q.info->head = tmp;
    q.info->size--;
    return data;
}

void * pqPeek(PQueue q)
{
    if(q.info == NULL)
    {
        q.info->ec = 1;
        return NULL;
    }
    return(q.info->head->data);
}

int pqGetSize(PQueue q)
{
    return((q.info)->size);
}

void pqFree(PQueue q)
{
    Node *current = q.info->head;
    while(current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(q.info);
    q.info->head = NULL;
    q.info->size = 0;
}
