#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
};
void deleteNode(struct Node **head,int pos)
{
struct Node *temp=*head;
struct Node *prev;
if(pos==0)
{
*head=temp->next;
free(temp);
return;
}
 for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;

  if (temp == NULL || temp->next == NULL)
    return;

    struct Node *next = temp->next->next;

    free(temp->next);  // Free memory

    temp->next = next;

}
void push(struct Node **head,int new_data)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=new_data;
new_node->next=(* head);
*head=new_node;
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
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
