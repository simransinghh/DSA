/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    queue<pair<TreeNode*,int>>q;
    vector<vector<int>> ans;
    if (A == NULL)  return ans;
    q.push(make_pair(A,0));
    vector<int> row;
    row.push_back(A->val);
    int maxlevel = 0;
    while(!q.empty()){
        pair<TreeNode*,int> x = q.front();
        q.pop();
        if(maxlevel<x.second+1){
            ans.push_back(row);
            row.clear();
            maxlevel = x.second + 1;
        }
        if (x.first->left != NULL){
            pair<TreeNode*,int> leftt(x.first->left,x.second+1);
            q.push(leftt);
            row.push_back(leftt.first->val);
        }
        if (x.first->right != NULL){
            pair<TreeNode*,int> rightt(x.first->right,x.second+1);
            q.push(rightt);
            row.push_back(rightt.first->val);
        }
    }
    
    return ans;
    
}
