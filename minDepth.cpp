/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
int Solution::minDepth(TreeNode* A) {

if(A==NULL)
return 0;

int lm = minDepth(A->left);
int rm = minDepth(A->right);

if(lm==0 or rm==0)
return lm+rm+1;
else
return min(lm,rm) + 1;
}
