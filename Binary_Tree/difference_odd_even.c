#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// binary tree node
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// return new node
Node *createNode (int data)
{
  Node *x = malloc(sizeof(Node));
  x->data = data;
  x->left = x->right = NULL;
}

// insert into tree
Node *insert (Node *x, int data)
{
  if (x == NULL)
    return createNode(data);

  if (data < x->data)
    x->left = insert(x->left, data);
  else if (data > x->data)
    x->right = insert(x->right, data);

  return x;
}

// Queue implementation
typedef struct
{
  Node *arr[100];
  int head, tail;
} Queue;

Queue queue = {.head = 0, .tail = 0};

// push to queue
void push(Node *x)
{
  queue.arr[queue.tail++] = x;
}

// pop
void pop(void)
{
  queue.head++;
}

// empty queue
int is_empty(void)
{
  return queue.tail - queue.head == 0;
}

// peek
Node *peek(void)
{
  return queue.arr[queue.head];
}

// size of queue
int size(void)
{
  return queue.tail - queue.head;
}

// return diff of sum
int diff_sum (Node *root)
{
  int level=0;
  int t=0;
  int k=1;
  int even=0;
  int odd=0;
  push(root);
  while(!is_empty())
  {
      t=k;
      k=0;
      level+=1;
      while(!is_empty() && t!=0)
      {
         Node* temp=peek();
         pop();

         if(level%2==0)
            even=even+temp->data;
         else
            odd=odd+temp->data;

         if(temp->left)
         {
             k++;
         push(temp->left);
         }

         if(temp->right)
         {
             k++;
            push(temp->right);
         }

         t--;
      }
  }
  return (odd-even);
}

// Main function
int main(void)
{
  int nodes;
  scanf("%d", &nodes);

  Node *root = NULL;
  for (int i = 0; i < nodes; i++)
  {
    int n;
    scanf("%d", &n);
    root = insert(root, n);
  }

  printf("%d\n", diff_sum(root));
}
