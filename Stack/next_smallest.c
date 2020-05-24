#include<stdio.h>
#include<stdlib.h>
typedef struct sNode
 {
     int data;
     struct sNode* next;
 }stack;
 stack* s=NULL;
 void push(int new_data)
{
  stack* new_node = (stack*) malloc(sizeof(stack));
  new_node->data  = new_data;
  new_node->next = s;
  s=new_node;
}
int pop()
{
  stack *temp;
   int t;
   temp=s;
   t=temp->data;
   s=s->next;
   temp->next=NULL;
   free(temp);
     return t;
}
int isEmpty()
{
    if(s==NULL)
    return 1;
    else
    return 0;
}
int peek()
{
    if(s==NULL)
    return 0;
    else
    return s->data;
}

int main()
{
int n,j=0;
scanf("%d",&n);
int A[n],res[n];
for(int i=0;i<n;i++)
{
    scanf("%d",&A[i]);
    res[i]=-1;
}
for(int i=n-1;i>=0;i--)
{
    if(isEmpty() || A[peek()]<=A[i])
    push(i);
    else{
        while(!isEmpty() && A[peek()]>A[i])
        {
            res[peek()]=A[i];
            pop();
        }
        push(i);
    }
}
for(int i=0;i<n;i++)
{
printf("%d -> %d\n",A[i],res[i]);
}
return 0;
}
