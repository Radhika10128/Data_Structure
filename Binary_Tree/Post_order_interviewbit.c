int *arr;
int i;
void inorder(treenode* A)
{
    if(A->left!=NULL)
    inorder(A->left);
    if(A->right!=NULL)
    inorder(A->right);
    arr[i++]=A->val;
}
int* postorderTraversal(treenode* A, int *len1) {
    arr=(int *)malloc(sizeof(int)*3000000);
    i=0;
    inorder(A);
    *len1=i;
    return arr;
}