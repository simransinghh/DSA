/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL) return 1;
    if(A==NULL || B==NULL) return 0;
    if(A->val != B->val) return 0;
    int l = isSameTree(A->left,B->left);
    int r = isSameTree(A->right,B->right);
    if(l==0 || r==0) return 0;
    return 1;
}
