#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void push(struct node **head,int new_data)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=new_data;
new_node->next=(* head);
*head=new_node;
}
void insertPos(struct node** head,int pos,int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    if(pos==0)
    {
     new_node->next=*head;
     *head=new_node;
    }
    struct node* temp=*head;
    struct node* prev=NULL;
    for(int i=0;i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
        prev=temp;
    }
    new_node->next=prev->next;
    prev->next=new_node;
}
void printList(struct node *ode)
{
while(ode!=NULL)
{
printf("%d",ode->data);
ode=ode->next;
}
}
int main()
{
    struct node* head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    insertPos(&head,2,9);
    printList(head);
}
