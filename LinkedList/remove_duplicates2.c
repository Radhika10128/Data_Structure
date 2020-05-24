#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

/* The function removes duplicates from a sorted list */
struct Node* removeDuplicates(struct Node* head)
{
    struct Node* current = head;
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    struct Node* h=head;
    while(ptr2->next!=NULL)
    {
    while(ptr2->data==ptr2->next->data)
    {
    ptr2=ptr2->next;
    }
    if(ptr1->next!=ptr2)
    {
    ptr1=ptr2;
    h=ptr1;
    }
    else
    {
    h=&(ptr1->next);
    ptr1=ptr2;
    }
    ptr2=ptr1->next;
    }
    head=h;
    return head;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
}
int main()
{
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    printf("\n Linked list before duplicate removal  ");
    printList(head);

    removeDuplicates(&head);

    printf("\n Linked list after duplicate removal ");
    printList(head);

    return 0;
}
