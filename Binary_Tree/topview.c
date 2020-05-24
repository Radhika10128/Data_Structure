
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int val;
    struct node* left;
    struct node* right;

}node;


node* createBinary(node* root, int d, int v)
{
    if( root == NULL)
    {
        node* nn = (node*)malloc(sizeof(node));
        nn->data = d;
        nn->val = v;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left, d, v-1);
    }
    else
    {
        root->right = createBinary(root->right,d, v+1);
    }
    return root;
}

// queue implementation
typedef struct
{
  node *arr[100];
  int head, tail;
} Queue;

Queue queue = {.head = 0, .tail = 0};

void queue_push(node *x)
{
  queue.arr[queue.tail++] = x;
}

void queue_pop(void)
{
  queue.head++;
}

int queue_is_empty(void)
{
  return queue.tail - queue.head == 0;
}

node *queue_peek(void)
{
  return queue.arr[queue.head];
}
void top_view(node *root)
{
  int arr[100];
  int center=50;
  int i;
  for(i=0;i<100;i++)
    arr[i]=0;

 queue_push(root);

  while(!queue_is_empty())
  {
    node* st=queue_peek();
    queue_pop();

    int index=st->val;

    if(arr[center+index]==0)
        arr[center+index]=st->data;

    if(st->left)
        queue_push(st->left);

    if(st->right)
        queue_push(st->right);
  }
  for(int i=0;i<100;i++)
  {
    if(arr[i]!=0)
      printf("%d ",arr[i]);
  }
}

int main()
{
  int num;
  scanf("%d", &num);

//   node *root = malloc(sizeof(node));
  node *root = NULL;
  int n;
  for (int i = 0; i < num; i++)
  {
    scanf(" %d", &n);
    root = createBinary(root, n, 0);
  }

  top_view(root);
    return 0;
}
