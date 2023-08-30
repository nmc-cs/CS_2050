#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

#typedef struct _Node
{
    void *data;
    struct _Node *next;
} Node;

typedef struct
{
    int ec;
    int listlen;
    Node *head;
    Node *tail;
} QueueInfo;

typedef struct
{
    QueueInfo *info;
} Queue;

int getQueueErrorCode(Queue pu);
Queue queueInit();
int enqueue(void *data, Queue p);
int getQueueSize(Queue p);
void *freeNode(Node *f);
void *dequeue(Queue p);
void freeQueue(Queue p);

int main(void)
{
    Queue p = queueInit();
    printf("%d is the size of the list.\n", getQueueSize(p));
}

int getQueueErrorCode(Queue pu)
{

}

Queue queueInit()
{
    Queue p;
    p.info = malloc(sizeof(QueueInfo));

    if(p.info)
    {
        QueueInfo *f = p.info;

        f->ec = 0;
        f->listlen = 0;

        Node *dummy = malloc(sizeof(Node));
        if(dummy)
        {
            dummy->next = NULL;
            f->head = dummy;
            f->tail = dummy;

        }
    }
    else
    {
        printf("Malloc failed!\n");
    }

    return p;
}

int enqueue(void *data, Queue p)
{
    Node *newt; //new tail
    newt = malloc(sizeof(Node))

    QueueInfo *f = p.info;

    if(newt)
    {
        newt->data = data;
        newt->next = NULL;

        Node *ctail = f->tail;

        f->tail = newt;
        ctail->next = newt;

        f->listlen += 1;
        f->ec = SUCCESS;
    }
    else
    {
        f->ec = FAILURE;
    }
    return f->ec;
}

void *freeNode(Node *f)
{
    if(f)
    {
        void *data = f->data;
        free(f);
        return data;
    }
    return NULL;
}

void *dequeue(Queue p)
{
    QueueInfo *f = p.info;
    int size = getQueueSize(p);
    if(size == SUCCESS)
    {
        return NULL;
    }

    void *data = freeNode(f->head->next);
    f->head->next = f->head->next->next;

    return data;
}

int getQueueSize(Queue p)
{
    return(p.info)->listlen;
}

void freeQueue(Queue p)
{
    Node *q;
    q = p.info->head;

    while(q)
    {
        Node *temp = q->next;
        free(q);
        q = temp;
    }

    free(p.info);
}
