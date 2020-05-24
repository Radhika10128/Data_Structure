int Solution::maxDepth(TreeNode* A) {
    if(A==NULL)
    return 0;
    else
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}