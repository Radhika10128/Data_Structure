int find(treenode* root,int elem)
 {
     if(root==NULL)
     return 0;
     if(root->val==elem)
     return 1;
     return find(root->left,elem) || find(root->right,elem);
 }
 
 treenode* path(treenode* A,int B,int C)
 {
        if(A==NULL)
        return NULL;
        if(A->val==B || A->val==C)
        return A;
        treenode* x=path(A->left,B,C);
        treenode* y=path(A->right,B,C);
        if(x && y)
        return A;
        if(x!=NULL)
        return x;
        if(y!=NULL)
        return y;
 }
 
int lca(treenode* A, int B, int C) {
   if(find(A,B)&&find(A,C))
   {
       treenode* ans=path(A,B,C);
       return ans->val;
   }
   else
   {
       return -1;
   }
}