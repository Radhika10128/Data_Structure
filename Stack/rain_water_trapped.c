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
        *top= temp->next;
        free(temp);
        temp=NULL;
}
int min(int a, int b)
{

    if(a<b)
        return a;
    else
        return b;
}
int max(int a,int b)
{
  return a>b?a:b;
}
int rainWater(int* A, int n)
{
  int water=0;
  int left[n],right[n];

  left[0]=A[0];
  for(int i=1;i<n;i++)
    left[i]=max(left[i-1],A[i]);

   right[n-1]=A[n-1];
  for(int i=n-2;i>=0;i--)
    right[i]=max(right[i+1],A[i]);

  for(int i=0;i<n;i++)
    water=water+(min(left[i],right[i])-A[i]);

  return water;
}


int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int r = rainWater(arr, n);
    printf("%d", r);
    return 0;
}
