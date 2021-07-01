int fun(TreeNode* A,TreeNode* B)
 {
     if(!A && !B) return 1;
    if(!A || !B) return 0;
    if(A->val!=B->val) return 0;
    return fun(A->left,B->right) && fun(A->right,B->left);
 }
int Solution::isSymmetric(TreeNode* A) {
    return fun(A->left,A->right);
}
