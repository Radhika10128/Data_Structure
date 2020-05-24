#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
};
void push(struct Node **head,int new_data)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=new_data;
new_node->next=(* head);
*head=new_node;
}
void insertAfter(struct Node *prev_node,int new_data)
{
    if(prev_node==NULL)
        return;
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));

    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
void append(struct Node **head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));

    new_node->data=new_data;
    new_node->next=NULL;

    struct Node *last=*head;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}
void printList(struct Node *node)
{
while(node!=NULL)
{
printf("%d",node->data);
node=node->next;
}
}
int main()
{
struct Node *head=NULL;
append(&head,6);
push(&head,7);
push(&head,1);
append(&head,4);
insertAfter(head->next,8);
printList(head);
}
