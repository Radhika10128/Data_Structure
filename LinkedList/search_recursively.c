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
bool search(struct Node *head,int key)
{
if(head==NULL)
return false;

if(head->data==key)
return true;

search(head->next,key);
}
int main()
{
struct Node* head = NULL;

   push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, 21)? printf("Yes") : printf("No");
    return 0;

}
