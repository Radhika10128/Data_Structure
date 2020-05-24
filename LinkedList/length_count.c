#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
int length(struct Node *head)
{
int count=0;
struct Node *current=head;
while(current!=NULL)
{
count++;
current=current->next;
}
return count;
}
int main()
{
struct Node* head = NULL;

   push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    printf("%d",length(head));
    return 0;
}
