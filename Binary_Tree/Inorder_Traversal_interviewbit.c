static int count=0;
 struct snode
 {
     treenode* t;
     struct snode* next;
 };
 void push(struct snode** s,treenode* t)
 {
     struct snode* new=(struct snode*)malloc(sizeof(struct snode));
     new->t=t;
     new->next=*s;
     *s=new;
 }
 int isEmpty(struct snode* s)
 {
     if(s==NULL)
     return 1;
     else
     return 0;
 }
 void pop(struct snode** s)
 {
     struct snode* tr;
     treenode* res;
     tr=*s;
     res=tr->t;
     *s=tr->next;
     free(tr);
 }
 treenode* peek(struct snode* s)
 {
     return s->t;
 }
 int countnodes(treenode* root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
int* inorderTraversal(treenode* A, int *len1) {
    int size=countnodes(A);
    treenode* curr=A;
    struct snode* s=NULL;
    int *arr=(int *)malloc(sizeof(int)*size);
    int j=0;
    while(!isEmpty(s) || curr)
    {
        while(curr)
        {
            push(&s,curr);
            curr=curr->left;
        }
        arr[j]=peek(s)->val;
        j++;
        curr=peek(s)->right;
        pop(&s);
    }
    *len1=j;
    return arr;
}