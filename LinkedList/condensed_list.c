#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct LinkedList
{
    struct node* head;
    struct node* tail;

};

typedef struct node node;
typedef struct LinkedList LinkedList;

node* createNode(int data)
{
    node* nn = (node*)malloc(sizeof(node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}
void insert(LinkedList* ll , int data)
{
        node* curr = ll->head;
        node* nn = createNode(data);
        if(curr == NULL)
        {
            ll->head = nn;
            ll->tail = nn;
        }
        else
        {
            ll->tail->next = nn;
            ll->tail = ll->tail->next;
        }
}
node* optimal(node* L) {
   node* ptr1=L;
   node* ptr2=NULL;
   while(ptr1!=NULL && ptr1->next!=NULL)
   {
       ptr2=ptr1;
       while(ptr2!=NULL && ptr2->next!=NULL)
       {
           if(ptr1->data==ptr2->next->data)
            ptr2->next=ptr2->next->next;
           else
            ptr2=ptr2->next;
       }
       ptr1=ptr1->next;
   }
   return L;
}

void printLinkedList( node* curr)
{

    while(curr)
    {
        printf("%d\n", curr->data);
        curr= curr->next;
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    int i;
    for(i=0;i<n;i++)
    {

        int num;
        scanf("%d", &num);
        insert(ll,num);
    }

    node* curr = optimal(ll->head);
    printLinkedList(curr);
    return 0;

}

