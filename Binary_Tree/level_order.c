#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
};
struct queue
{
    struct Tree* st;
    struct Tree* next;
};
void push(struct queue** front,struct queue** rear,struct Tree* s)
{
    struct queue* n=(struct queue*)malloc(sizeof(struct queue));
    n->st=s;
    n->next=NULL;
    if(*front==NULL&&*rear==NULL)
    {
        *front=n;
        *rear=n;
    }
    else
    {
        (*rear)->next=n;
        *rear=n;
    }
}
void pop(struct queue** front,struct queue** rear)
{
    if(front==rear)
    {
        *front=NULL;
        *rear=NULL;
    }
    else
    {
        *front=(*front)->next;
    }
}
void printLevelOrder(struct Tree* root)
{
    struct Tree* temproot = root;

    while(temproot != NULL)
    {
        printf("%c ", temproot->data);
        if(temproot->left != NULL)
        {push(temproot->left);
            }
        if (temproot->right !=NULL)
        {push(temproot->right);
            }
        temproot = pop();
        }
}
struct node* newNode(int data)
{
    struct Tree* node = (struct Tree*)
                        malloc(sizeof(struct Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int main()
{
    struct Tree *root = newNode(5);
    root->left = newNode(6);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(9);
    printLevelOrder(root);

    return 0;
}
