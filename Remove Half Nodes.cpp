TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return A;
    A->left = solve(A->left);
    A->right = solve(A->right);
    if(A->left==NULL && A->right==NULL) return A;
    if(A->left==NULL){
    return A->right;}
    if(A->right==NULL){
    return A->left;}
    return A;
}
