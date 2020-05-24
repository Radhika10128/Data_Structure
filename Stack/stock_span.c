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
void calculateSpan(int price[], int n, int S[])
{
    struct sNode* s=NULL;
    push(&s,0);

    S[0]=1;
    for(int i=1;i<n;i++)
    {
        while(!isEmpty(s) && price[peek(s)]<=price[i])
            pop(&s);

        S[i]=isEmpty(s)?(i+1):(i-peek(s));
        push(&s,i);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}
int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];


    calculateSpan(price, n, S);


    printArray(S, n);

    return 0;
}
