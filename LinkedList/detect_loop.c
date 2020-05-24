#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node **head,int new_data)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=new_data;
new_node->next=(* head);
*head=new_node;
}
int detectloop(struct Node *head)
{
struct Node *slowptr=head,*fastptr=head;
while(slowptr && fastptr && fastptr->next)
{
fastptr = fastptr->next->next;
slowptr = slowptr->next;
if(slowptr==fastptr)
{
printf("Loop found");
return 1;
}
}
return 0;
}
int main()
{
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;
    detectloop(head);

    return 0;
}
