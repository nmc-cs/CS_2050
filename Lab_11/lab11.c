#include "lab11.h"

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct BST{
    Node * root;
    int size;
}BST;

BST * initBST() // Makes a BST called tree by using malloc and make memory
{
    BST * tree = malloc(sizeof(BST)); //if malloc not work it will return NULL otherwise and set the root to NULL
    if(tree == NULL)
    {
        return NULL;
    }
    else
    {
        tree->root = NULL;
        tree->size = 0;
        return tree;
    }
}

Node * newNode(int data) //Help function to make new node that takes in a parameter to create a node with malloc
{
    Node * node = malloc(sizeof(Node)); //checks to se if malloc is working or not otherwise it will return null
    if(node == NULL)
    {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insertHelp(Node ** node, int data) // help function for inserting BST
{
    if(*node == NULL) //checks to see if current is null and if it is it makes a new node by calling the function and passing data
    {
        *node = newNode(data);
        return 0;
    }
    if(data < (*node)->data)
    {
        return insertHelp(&((*node)->left),data);
    }
    if(data > (*node)->data)
    {
        return insertHelp(&((*node)->right),data); //the otherhand it compares data value with node value and calls itself
    }
    return 1;
}

int insertBST(BST *tree, int data) //Takes in 2 paramenters and checks if tree is null
{
    if(tree == NULL)
    {
        return 1;
    }
    else //if not null it calls help fucntion to insert BST into corrent area
    {
        int result = insertHelp(&(tree->root), data);
        if(result == 0)
        {
            tree->size++;
        }
        return result;
    }
}

int getSizeBST(BST* tree) //takes a tree as paramenter and sees if it is emtpy
{
    if(tree == NULL)
    {
        return 0;
    }
    return tree->size;
}

int getMaxBST(BST* tree) // takes tree as paramenter and sets current to check right side of tree and loops through until it get to NULL
{
   Node * current = tree->root;
   while(current->right != NULL)
   {
        current = current->right;
   }
   return current->data;
}

void orderPrintHelp(Node *node) //help function using recursion to go though left and right nodes
{
if(node == NULL)
 {
    return;
 }
 orderPrintHelp(node->left);
 orderPrintHelp(node->right);
 printf("%d ", node->data);
}

void postOrderPrintBST(BST* tree) //checks if it is null and if not it goies to help function and suse recursion to print values
{
if(tree == NULL || tree->root == NULL)
{
    return;
}
    orderPrintHelp(tree->root);
}

void freeHelp(Node * node) // Using a help function to free nodes using recursion and frees them along the way
{
    if(node == NULL)
    {
        return;
    }
    freeHelp(node->left);
    freeHelp(node->right);
    free(node);
}

void freeBST(BST* tree) //checks and sees if tree is null and if not it calls freehelp and uses recursion to free the tree
{
    if(tree == NULL)
    {
        return;
    }
    freeHelp(tree->root);
    free(tree);
}
