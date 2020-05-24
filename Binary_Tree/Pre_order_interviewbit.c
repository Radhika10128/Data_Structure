static int count=0;
 struct snode
 {
     treenode* t;
     struct snode* next;
 };
void push(struct snode** s,treenode* d)
{
    struct snode* new=(struct snode*)malloc(sizeof(struct snode));
    new->t=d;
    new->next=*s;
    *s=new;
}
treenode* peek(struct snode* s)
{
    return s->t;
}
int isempty(struct snode* s)
{
    if(s==NULL)
    return 1;
    else
    return 0;
}
void pop(struct snode** s)
{
    treenode* res;
    struct snode* tr;
    tr=*s;
    res=tr->t;
    *s=tr->next;
    free(tr);
}
int countnodes(treenode* root)
{
    if(root!=NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
int* preorderTraversal(treenode* A, int *len1) {
    int size=countnodes(A);
    int *arr=(int *)malloc(sizeof(int)*size);
    int j=0;
    treenode* curr=A;
    struct snode* s=NULL;
    while(!isempty(s) || curr)
    {
        while(curr)
        {
            arr[j]=curr->val;
            j++;
            push(&s,curr);
            curr=curr->left;
        }
        curr=peek(s)->right;
        pop(&s);
    }
    *len1=j;
    return arr;
}