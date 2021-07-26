int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    if(A->left == NULL and A->right == NULL)
        return 1;
        
    if(A->left==NULL)
        return 1 + minDepth(A->right);
     
    if(A->right==NULL)
        return 1 + minDepth(A->left);  
    return 1 + min(minDepth(A->left),minDepth(A->right));
}
