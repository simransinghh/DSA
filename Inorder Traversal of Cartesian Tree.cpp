/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A) {
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* root = new TreeNode(A[0]);
    TreeNode* last = root;
    parent[root] = NULL;
    for(int i=1;i<A.size();i++){
        TreeNode* neww = new TreeNode(A[i]);
        while(last->val < neww->val && last !=root){
            last = parent[last];
        }
        if(root->val < neww->val){
            parent[neww] = NULL;
            neww->left = root;
            root = neww;
        }
        else if(last->val > neww->val){
            neww->left = last->right;
            last->right = neww;
            parent[neww] = last;
            parent[neww->right] = neww;
        }
        else{
            last->right = neww;
            parent[neww] = last;
        }
        last = neww;
    }

    return root;
}
