#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
typedef struct LL
{
    int val;
    struct LL* next;
}LL;
void push(queue** front,queue** rear,STree* data)
{
    queue* node=(queue*)malloc(sizeof(queue));
    node->st=data;
    node->next=NULL;
    if(*front==NULL && *rear==NULL)
    {
        *front=node;
        *rear=node;
    }
    else
    {
        (*rear)->next=node;
        *rear=node;
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
    {
        *front=(*front)->next;
    }
}
int min=INT_MAX;
int max=INT_MIN;
void preorder(Tree* root,int d)
{
   if(root==NULL)
   return;

   if(d<min)
    min=d;
   if(d>max)
    max=d;

   preorder(root->left,d-1);
   preorder(root->right,d+1);
}
void verticalPrint(Tree* root)
{
    preorder(root,0);
    min=-min;
    int n=max>min?max:min;
    LL* arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]->val=i-(n/2);
        arr[i]->next=NULL;
    }
    //put root node in queue
    STree* sroot=(STree*)malloc(sizeof(STree));
    sroot->tnode=root;
    sroot->dist=0;
    queue* front=NULL;
    queue* rear=NULL;
    push(&front,&rear,sroot);
    //level order traversal using queue
    while(front&&rear)
    {
        int index=front->st->dist;
        int value=front->st->tnode->data;
        for(int i=0;i<n;i++)
        {
            if(arr[i]->val==index)
            {
                LL* e=(LL*)malloc(sizeof(LL));
                e->next=NULL;
                e->val=value;
                LL* ptr=arr[i];
                while(ptr && ptr->next)
                {
                    ptr=ptr->next;
                }
                ptr->next=e;
                break;
            }
        }
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
        printf("vertical print: \n");
        for(int i=0;i<n;i++)
        {
        //printf("%d  ",tV[i]->val);
        LL* ptr=arr[i]->next;
        while(ptr)
        {
            printf("%d ",ptr->val);
            ptr=ptr->next;
        }
        //printf("\n");
        }

    }
}
//Binary Search Tree for creation of tree(input)
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

//create the tree as an input
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
}
int main()
{
    Tree* root=NULL;
    createTree(&root);
    verticalPrint(root);
}

