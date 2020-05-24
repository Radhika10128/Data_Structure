#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
//Tree
typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
}Tree;

//STree
typedef struct STree
{
    struct Tree* Tnode;
    int dist;
}STree;

//queue implementation
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

//array of LL
typedef struct LL
{
    int val;
    struct LL* next;
}LL;

//check the input.
int min=INT_MAX;
int max=INT_MIN;
void preorderTraversal(Tree* root,int d)
{
    if(root==NULL)
        return;
    if(d<min)
        min=d;
    if(d>max)
        max=d;
    //printf("%d ",root->data);
    preorderTraversal(root->left,d-1);
    preorderTraversal(root->right,d+1);
}

//top view of tree implementation
void verticalPrint(Tree* root)
{
    preorderTraversal(root,0);
    min=-min;
    int n=max>min?max:min;
    n=n*2+1;

    int i;
    LL* tV[n];
    for(i=0;i<n;i++)
        tV[i]=(LL*)malloc(sizeof(LL));

    for(i=0;i<n;i++)
    {
        tV[i]->val=i-(n/2);
        tV[i]->next=NULL;
    }
    //put root node in queue
    STree* sroot=(STree*)malloc(sizeof(STree));
    sroot->Tnode=root;
    sroot->dist=0;
    queue* front=NULL;
    queue* rear=NULL;
    push(&front,&rear,sroot);
    //level order traversal using queue
    while(front&&rear)
    {
        //top view elements in array
        int index=front->st->dist;
        int value=front->st->Tnode->data;
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
        if(front->st->Tnode->left)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist-1;
            nn->Tnode=front->st->Tnode->left;
            push(&front,&rear,nn);
        }
        //check right
        if(front->st->Tnode->right)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist+1;
            nn->Tnode=front->st->Tnode->right;
            push(&front,&rear,nn);
        }
        //remove that element from queue
        pop(&front,&rear);

    }
    //print top view
    printf("vertical print: \n");
    for(i=0;i<n;i++)
    {
        //printf("%d  ",tV[i]->val);
        LL* ptr=tV[i]->next;
        while(ptr)
        {
            printf("%d ",ptr->val);
            ptr=ptr->next;
        }
        //printf("\n");
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
