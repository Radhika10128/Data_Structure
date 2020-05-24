#include<stdio.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void insertAtBeg(int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=front;
    n->prev=NULL;
    front=n;
    if(front->next)
        front->next->prev=front;
    else
        rear=front;
}
void insertAtEnd(int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(front==NULL)
    {
        front=n;
        front->prev=NULL;
        rear=front;
    }
    else
    {
        n->prev=rear;
        rear->next=n;
        rear=rear->next;
    }
}

void deleteAtBeg()
{
    if(front==NULL)
        return;
    struct node* temp=front;
    front=front->next;
    if(front)
        {front->prev=NULL;}
    if(!front)
        {rear=NULL;}
    free(temp);
}
void deleteAtEnd()
{
    if(!front)
        return;
    struct node* temp=rear;
    rear=rear->prev;
    if(rear)
        rear->next=NULL;
    else
        front=NULL;
    free(temp);
}
void print()
{
    struct node *curr=front;
    while(curr)
    {
        printf("%u->%d->%u  ",curr->prev,curr->data,curr->next);
        curr=curr->next;
    }
    printf("\n");
}


int main()
{

    int n,i;
    printf("Enter size of an array\n");
    scanf("%d",&n);
    printf("\nEnter elements in an array: ");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int k;
    printf("\nEnter window size ");
    scanf("%d",&k);
    int b[n-k+1];
    int x=0;
    for(i=0;i<n;i++)
    {
        if(!front||a[i]<=(a[rear->data]))
        {
            insertAtEnd(i);
        }
        else
        {
            while(front&&a[rear->data]<a[i])
            {
                deleteAtEnd();
            }

        }
        if(!front||(rear->data-front->data)<k-1)
            ;
        else
            deleteAtBeg();
        insertAtEnd(i);
        if(i>=k-1)
            b[x++]=a[front->data];
        print();
    }
    printf("Output : ");
    for(i=0;i<x;i++)
    {
        printf("%d ",b[i]);
    }
}

