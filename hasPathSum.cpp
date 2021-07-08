int istrue(TreeNode* root, int sum){
if(!root){
    return 0;
}
if(!root->left && !root->right && root->val == sum){
    return 1;
}
return max(istrue(root->left,sum - root->val),istrue(root->right, sum - root->val));
}
int Solution::hasPathSum(TreeNode* A, int B) {
return istrue(A,B);
}
