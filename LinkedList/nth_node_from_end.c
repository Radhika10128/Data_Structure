#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node
{
    int data;
    struct Node* next;
};

void printLast(struct Node *head,int n)
{
int count=0;
struct Node *temp=head;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
if(count<n)
return;

temp=head;
for(int i=1;i<count-n+1;i++)
{
temp=temp->next;
}
printf("%d",temp->data);
return;
}

void push(struct Node** head_ref, int new_data)
{
struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


int main()
{
struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printLast(head, 4);
    return 0;
}
