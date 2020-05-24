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
int GetNth(struct Node* head, int index)
{

    struct Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
}
int main()
{
struct Node* head = NULL;

   push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    printf("Element at index 3 is %d",GetNth(head, 3));
    return 0;
}
