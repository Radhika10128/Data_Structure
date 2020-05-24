#include<stdio.h>
#include<stdlib.h>
#define bool int

/* structure of a stack node */
struct sNode
{
   char data;
   struct sNode *next;
};
void push(struct sNode** top_ref, int new_data)
{
  /* allocate node */
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));

  if (new_node == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }

  /* put in the data  */
  new_node->data  = new_data;

  /* link the old list off the new node */
  new_node->next = (*top_ref);

  /* move the head to point to the new node */
  (*top_ref)    = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
  char res;
  struct sNode *top;

  /*If stack is empty then error */
  if (*top_ref == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
int isEmpty(struct sNode* root)
{
    return !root;
}
int peek(struct sNode* root)
{
    return root->data;
}
struct sNode* sort(struct sNode* s)
{
   struct sNode* temp=NULL;
   push(&temp,peek(s));
   pop(&s);
   while(!isEmpty(s))
   {
    int d=peek(s);
    pop(&s);
    while(!isEmpty(temp) && peek(temp)<d)
    {
    push(&s,peek(temp));
    pop(&temp);
    }
    push(&temp,d);
   }
   return temp;
}
int main()
{
    struct sNode* input = NULL;

    push(&input,34);
    push(&input,3);
    push(&input,31);
    push(&input,98);
   push(&input,92);
   push(&input,23);

    struct sNode* tmpStack=sort(input);
   while (!isEmpty(tmpStack))
    {
        printf("%d ",peek(tmpStack));
        pop(&tmpStack);
    }

    return 0;
}
