#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));

    new->data = data;
    new->next = *top;
    *top = new;

}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{

        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;
}
long long int getMaxArea(int* hist, int n)
{
  st* head = NULL;
  long long int max=INT_MIN;
  for(int i=0;i<n;i++)
  {
    if(empty(head) || hist[i]>=hist[peek(head)])
      push(&head,i);
    else
    {
      while(!empty(head) && hist[i]<hist[peek(head)])
      {
        long long int x=hist[peek(head)];
        pop(&head);
        long long int dist=empty(head)?i:(i-peek(head)-1);
        long long int area=x*dist;
        if(area>max)
          max=area;
      }
      push(&head,i);
    }
  }
  while(!empty(head))
  {
    long long int x=hist[peek(head)];
    pop(&head);
    long long int dist=empty(head)?n:(n-peek(head)-1);
    long long int area=x*dist;
    if(area>max)
      max=area;
  }
  return max;
}

int main() {
   while(1)
   {
    int n;
    scanf("%d", &n);
    if(n==0)
       break;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);

    }

    long long int r = getMaxArea(arr, n);
    printf("%lld\n", r);
   }
    return 0;
}
