/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> v;
    if(A==NULL) return v;
    TreeNode* curr=A;
        
//     while(A != NULL){
        
//         ans.push_back(A->val);
//         s.push(A);
//         A = A->left;    
//     }
    
    
//     if(s.empty()){
//         break;
//     }
    
//     A = s.top();
//     s.pop();
//     A = A->right;
    
// }
// return ans;
    while(!s.empty() || curr){
        while(curr){
            v.push_back(curr->val);
            s.push(curr);
            curr=curr->left;
        }
        TreeNode* temp=s.top();
        s.pop();
        curr=temp->right;
    }
    return v;
}
