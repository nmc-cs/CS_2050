#include "lab7.h"

struct _Node{
    struct _Node *next;
    void *data;
} typedef Node;

typedef struct Info
{
    Node *head;
    int size;
} Info;


Stack initStack()
{
    Stack newStack; //create a new stack name
    newStack.info = malloc(sizeof(Info)); //allocate memory to the struct Info
    if(newStack.info == NULL) //if the initialization failed we set it to null
    {
        newStack.info = NULL;
        return newStack;
    }

    newStack.info->size = 0; //newStack points to size and sets to 0
    newStack.info->head = NULL; //newStack points to head and sets to NULL
    return newStack;
}

int getSize(Stack s)
{
    return(s.info)->size; //returns th enumber of elements on the stack
}

void * peekStack(Stack s)
{
    if(s.info->size == 0) //info points to size and if it equals zero return null
    {
        return NULL;
    }

    return s.info->head->data; //returns the element at the top of the stack without removing it
}

int pushStack(Stack s, void *data)
{
    Node *newNode = malloc(sizeof(Node)); //allocates memory for the newNode
    if(newNode == NULL) //checks if there is enough memory
    {
        return 1; //not successful
    }

    //Takes a stack and data item and pushes the item onto the top of the stack and then returns 0 if it was successful
    newNode->data = data;
    newNode->next = s.info->head;
    s.info->head = newNode;
    s.info->size++;

    return 0;
}

void * popStack(Stack s)
{
    if(s.info->size == 0) //sets info to size and if it is empty it will return NULL
    {
        return NULL;
    }

    //takes a stack and then it pops the data item from the top of the stack.
    //Returns the item popped from the stack
    Node *temp = s.info->head;
    void *data = temp->data;
    s.info->head = temp->next;
    s.info->size--;
    free(temp);
    return data;
}


// Takes a stack and then returns elelment at the given index and it doesnt remove it
//if tthe index isnt valid for the stack we returned null;
void * getAtIndex(Stack s, int index)
{
    if(index > getSize(s) || index < 0)
    {
        return NULL;
    }
    Node *current = s.info->head;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

void freeStack(Stack s)
{
   //Takes a stack and then frees all the memory we allocated to the stack
    Node *current = s.info->head;
    while(current)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(s.info);
    s.info->head = NULL;
    s.info->size = 0;
}
