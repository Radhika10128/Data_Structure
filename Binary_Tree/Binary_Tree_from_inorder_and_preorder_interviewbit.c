int search(int arr[],int start,int end,int B)
 {
     int i;
     for(i=start;i<=end;i++)
     {
         if(arr[i]==B)
         break;
     }
     return i;
 }
 treenode* createTree(int A[],int B[],int start,int end,int* index)
 {
     if(start>end)
     return NULL;
     treenode* root=treenode_new(B[*index]);
     (*index)++;
     if(start==end)
     return root;
     int i=search(A,start,end,root->val);
     root->left=createTree(A,B,start,i-1,index);
     root->right=createTree(A,B,i+1,end,index);
     return root;
 }
treenode* buildTree(int* A, int n1, int* B, int n2) {
    int index=0;
    return createTree(B,A,0,n1-1,&index);
}