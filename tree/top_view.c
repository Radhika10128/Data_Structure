#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
}Tree;
typedef struct STree
{
    struct Tree* tnode;
    int dist;
}STree;
typedef struct queue
{
   struct STree* st;
    struct queue* next;
}queue;

void push(queue** front,queue** rear,STree* m)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->st=m;
    q->next=NULL;
    if(*front==NULL && *rear==NULL)
    {
        *front=q;
        *rear=q;
    }
    else
    {
        (*rear)->next=q;
         *rear=q;
    }
}
void pop(queue** front,queue** rear)
{
    if(*front==*rear)
    {
        *front=NULL;
        *rear=NULL;
    }
    else
        *front=(*front)->next;
}
void topView(Tree* root)
{
    int arr[100];
    for(int i=0;i<100;i++)
    arr[i]=0;
    int i=0;
    int center=50;
    STree* sroot=(STree*)malloc(sizeof(STree));         //put root node in queue
    sroot->tnode=root;
    sroot->dist=0;
    queue* front=NULL;
    queue* rear=NULL;
    push(&front,&rear,sroot);
    while(front && rear)
    {
        int index=front->st->dist;
        int value=front->st->tnode->data;
        if(arr[center+index]==0)
            arr[center+index]=value;
        if(front->st->tnode->left)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist-1;
            nn->tnode=front->st->tnode->left;
            push(&front,&rear,nn);
        }
        //check right
        if(front->st->tnode->right)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist+1;
            nn->tnode=front->st->tnode->right;
            push(&front,&rear,nn);
        }
        //remove that element from queue
        pop(&front,&rear);
    }
    printf("TOP VIEW: ");
    for(int i=0;i<100;i++)
    {
        if(arr[i]!=0)
            printf("%d ",arr[i]);
    }
}
Tree* BST(Tree* root,int data)
{
    if(root==NULL)
    {
        Tree* n=(Tree*)malloc(sizeof(Tree));
        n->data=data;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    else if(data<root->data)
    {

        root->left=BST(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=BST(root->right,data);
    }
    return root;
}

void createTree(Tree** root)
{
    *root=BST(*root,10);
    *root=BST(*root,6);
    *root=BST(*root,12);
    *root=BST(*root,7);
    *root=BST(*root,4);
    *root=BST(*root,11);
    *root=BST(*root,14);
    *root=BST(*root,5);
    *root=BST(*root,13);
    *root=BST(*root,3);
    *root=BST(*root,16);
    *root=BST(*root,15);
    *root=BST(*root,1);
    *root=BST(*root,2);
    printf("Elements pushed in Binary Search tree: 10 6 12 7 4 11 14 5 13 3 16 15 1 2\n");
}
int main()
{
   Tree* root=NULL;
    createTree(&root);
    topView(root);
}
