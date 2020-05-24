#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

void printMiddle(struct Node *head)
{
  struct Node *current=head;
  if(head==NULL)
    return;
  struct Node *slow=head,*fast=head;
  while(slow && fast->next && fast->next->next)
  {
      slow=slow->next;
      fast=fast->next->next;
  }
  struct Node *temp=slow->next;
  printf("%d",slow->data);
  slow->next=NULL;
  struct Node *head1=head;
  struct Node *head2=temp;
  struct Node *curr=head1;
  head1=head1->next;
  printf("%d",head2->data);
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
