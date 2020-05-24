#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void printList(struct node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void split(struct node* head,struct node** slow,struct node** fast)
{
    struct node* slow_ptr=head;
    struct node* fast_ptr=head->next;
    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    *slow=head;
    *fast=slow_ptr->next;
    slow_ptr->next=NULL;
}
struct node* Sort(struct node* a,struct node* b)
{
    struct node* result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

        if(a->data<=b->data)
        {
            result=a;
            result->next=Sort(a->next,b);
        }
        else
        {
            result=b;
            result->next=Sort(a,b->next);
        }

    return result;
}
void MergeSort(struct node** head_ref)
{
    struct node* head=*head_ref;
    if(head==NULL || head->next==NULL)
        return;
    struct node* a;
    struct node* b;
    split(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *head_ref=Sort(a,b);
}
int main()
{
    struct node* res = NULL;
    struct node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    MergeSort(&a);
    printf("Sorted Linked List is: \n");
    printList(a);
    getchar();
    return 0;
}
