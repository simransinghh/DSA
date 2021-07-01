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
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return A;
    TreeNode* l = A->left;
    A->left = invertTree(A->right);
    A->right = invertTree(l);
    return A;
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
int fun(TreeNode* A,TreeNode* B)
 {
     if(!A && !B) return 1;
    if(!A || !B) return 0;
    if(A->val!=B->val) return 0;
    return fun(A->left,B->right) && fun(A->right,B->left);
 }
int Solution::isSymmetric(TreeNode* A) {
    return fun(A->left,A->right);
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
 int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL) return 1;
    if(A==NULL || B==NULL) return 0;
    if(A->val != B->val) return 0;
    int l = isSameTree(A->left,B->left);
    int r = isSameTree(A->right,B->right);
    if(l==0 || r==0) return 0
    return 1;
}

TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(B==NULL) return A;
    if(A==NULL) return B;
    if(A==NULL && B==NULL) return NULL;
    A->val += B->val;
    A->left = solve(A->left,B->left);
    A->right = solve(A->right,B->right);
    return A;
}




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


int Solution::isBalanced(TreeNode* A) {
    if(A==0) return -1;
    int l = isBalanced(A->left);
    int r = isBalanced(A->right);
    if(l==0 || r==0) return 0;
    if(l==-1) l=0;
    if(r==-1) r=0; 
    if(l==r || l == r+1 || l+1 == r){
        return(max(l,r)+1);
    }
    return 0;
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
TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return A;
    if(A->left==NULL && A->right==NULL) return A;
    else if(A->left==NULL || A->right==NULL){
        return NULL;
    }
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL) return ans;
    if(A->val==B){
        ans.push_back(B);
        return ans;
    }
    vector<int> l = solve(A->left,B);
    vector<int> r = solve(A->right,B);
    if(!l.empty()){
        l.insert(l.begin(),A->val);
        return l;
    }else if(!r.empty()){
        r.insert(r.begin(),A->val);
        return r;
    }
    return ans;
}



bool one = false;
bool two = false;
void recovering(TreeNode* root,int &prev1,int& next1,int &prev2,int &next2){
    if(one && two) return;
    if(root==NULL) return;
    // cout<<endl<<root->val<<"-";
    recovering(root->left,prev1,next1,prev2,next2);
    if(!one){
        if(root->val < prev1){
            one = true;
            next1 = root->val;
            // cout<<"n1"<<root->val<<endl;
        }
        else{ 
            // cout<<"p1"<<root->val<<endl;
            prev1 = root->val;
        }
    }
    else if(!two){
       if(root->val < prev2){
           next2 = root->val;
        //   cout<<"n2"<<root->val<<endl;
           two = true;
        }
        else{ 
            // cout<<"p2"<<root->val<<endl;
            prev2 = root->val; 
        }
    }
    else if(one && two) return;
    prev2 = root->val;
    // cout<<"r"<<prev2<<"   ";
    recovering(root->right,prev1,next1,prev2,next2);
    return;
}
vector<int> Solution::recoverTree(TreeNode* A) {
    int prev1 = INT_MIN;
    int prev2 = INT_MIN;
    int next1,next2;
    one = false;
    two = false;
    recovering(A,prev1,next1,prev2,next2);
    vector<int> ans;
    // cout<<prev1<<next1<<prev2<<" "<<next2<<" "<<one<<two<<endl;
    if(!two){
       ans.push_back(next1);
       ans.push_back(prev1);
       return ans;
    }
    ans.push_back(next2);
    ans.push_back(prev1);
    return ans;
}

int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
