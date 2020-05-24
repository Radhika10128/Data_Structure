#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};
void reverse(struct Node* slowptr)
    {
        struct Node* current = slowptr;
        struct Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        slowptr = prev;
    }
void printMiddle(struct Node *head)
{

    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            }
    }
    struct Node *head1=head;
    struct Node *head2=slow_ptr;
    slow_ptr=NULL;
    reverse(head2);
    struct Node *curr=head1;
    //printf("%d",head1->data);
    //printf("%d",head2->data);
    while(head1 || head2)
    {
        if(head2)
        {
            curr->next=head2;
            head2=head2->next;
            curr=curr->next;
        }
        if(head1)
        {
            curr->next=head1;
            head1=head1->next;
            curr=curr->next;
        }
    }

}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =  (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node* head = NULL;
    int i;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printMiddle(head);
    printList(head);


    return 0;
}
