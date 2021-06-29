#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int minno = -1;
bool once = false;
int Solution::kthsmallest(TreeNode* A, int B) {
    if(A==NULL) return -1;
    if(A->left==NULL && A->right==NULL && !once){
        once = true;
        minno = 1;
        if(B==1) return A->val;
        return -1;
    }
    int a = kthsmallest(A->left,B);
    minno++;
    if(minno==B) return A->val;
    int b = kthsmallest(A->right,B);
    if(a != -1) return a;
    else return b;
}

vector<int> v;
void inorder(TreeNode* root, int k)
{
if(root==NULL) return;
inorder(root->left, k);
v.push_back(root->val);
if(v.size()>=k) return;
inorder(root->right, k);
}

int Solution::kthsmallest(TreeNode* root, int k) {
v.clear();
if(root==NULL) return 0;
inorder(root, k);
return v[k-1];
}

iint Solution::solve(vector<int> &A) {
    stack<int> ihatetnp;
    int minnow = INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i] < minnow){
            // cout<<i<<" "<<A[i]<<" "<<minnow<<endl;
            return 0;
        }
        if(ihatetnp.empty()){
            ihatetnp.push(A[i]);
            continue;
        }
        else if(ihatetnp.top()>=A[i]){
            ihatetnp.push(A[i]);
        }
        else{
            while(!ihatetnp.empty() && ihatetnp.top()<A[i]){
                minnow = ihatetnp.top();
                ihatetnp.pop();
            }
            ihatetnp.push(A[i]);
        }
    }
    return 1;
}

int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
