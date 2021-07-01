int height(TreeNode* root)
{
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}
int Solution::isBalanced(TreeNode* root) {
    if(!root) return 1;
    if(abs(height(root->left)-height(root->right))>1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}
