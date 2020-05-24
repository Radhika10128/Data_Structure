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

void push(queue** front,queue** rear,STree* s)
{
    queue* n=(queue*)malloc(sizeof(queue));
    n->st=s;
    n->next=NULL;
    if(*front==NULL && *rear==NULL)
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
typedef struct LL
{
    int val;
    struct LL* next;
}LL;
int min=-367378;
int max=336474;
int preorder(Tree* root,int h)
{
    if(root==NULL)
        return NULL;
    if(h<min)
        min=h;
    if(h>max)
        max=h;

    preorder(root->left,h-1);
    preorder(root->right,h+1);
}
void verticalPrint(Tree* root)
{
    preorder(root,0);
    min=-min;
    int n=max>min?max:min;
    n=n*2+1;
    int i;
    LL *tV[n];
    for(int i=0;i<n;i++)
        tV[i]=(LL*)malloc(sizeof(LL));
    for(i=0;i<n;i++)
    {
        tV[i]->val=i-(n/2);
        tV[i]->next=NULL;
    }

    STree* sroot=(STree*)malloc(sizeof(STree));
    sroot->tnode=sroot;
    sroot->dist=0;
    queue* front=NULL;
    queue* rear=NULL;
    push(&front,&rear,sroot);

    while(front && rear)
    {
        int index=front->st->dist;
        int value=front->st->tnode->data;
        //error here
        for(i=0;i<n;i++)
        {
            if(tV[i]->val==index)
            {
                LL* ne=(LL*)malloc(sizeof(LL));
                ne->next=NULL;
                ne->val=value;
                LL* ptr=tV[i];
                while(ptr&&ptr->next)
                {
                    ptr=ptr->next;
                }
                ptr->next=ne;
                break;
            }
        }

        //check left
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
    //print top view
    printf("vertical print: \n");
    for(i=0;i<n;i++)
    {
        LL* ptr=tV[i]->next;
    while(ptr)
        {
            printf("%d ",ptr->val);
            ptr=ptr->next;
        }
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
        root->left=BST(root->left,data);
    else if(data>root->data)
        root->right=BST(root->right,data);

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
}
int main()
{
Tree* root=NULL;
    createTree(&root);
    verticalPrint(root);
}
