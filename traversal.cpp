#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<pair<TreeNode*,int>> s;
    vector<int> v;
    if(A==NULL) return v;
    TreeNode* curr=A->left;
    s.push(make_pair(A,0));
    while(!s.empty()){
        while(curr){
            s.push(make_pair(curr,0));
            curr=curr->left;
        }
        pair<TreeNode*,bool> temp = s.top();
        if(temp.second){
            s.pop();
            v.push_back(temp.first->val);
        }else{
            s.top().second = true;
            curr=temp.first->right;
        }
    }
    return v;
}



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



vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> v;
    if(A==NULL) return v;
    TreeNode* curr=A->left;
    s.push(A);
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        pair<TreeNode*,bool> temp=s.top();
        if(temp.second){
            s.pop;
            v.push_back(temp->val);
        }else{
            s.top().second = true;
        }
        curr=temp->right;
    }
    return v;
}

int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
