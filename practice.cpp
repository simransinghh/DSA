#include <bits/stdc++.h>
using namespace std;

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    int s=0,e=n-1;
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(A[mid]);
    if(n==1) return root;
    if(n==2){
        Treenode* sec = new Treenode(A[1]);
        root->right = sec;
        return root;
    }
    vector<int> l(A.begin(),A.begin()+mid-1);
    vector<int> r(A.begin()+mid+1,A.end());
    root->left = sortedArrayToBST(l);
    root->right = sortedArrayToBST(r);
    return root;
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
TreeNode* buildTreeeee(vector<int> &A, int idx){
    TreeNode* r = new TreeNode(x);
    int x = A[idx];
    if(idx==A.size()-1){
        return r;
    }
    TreeNode* after = buildTreeeee(A,idx+1);
    if(after->val < x){
        r->right = after;
        return r;
    }
    TreeNode temp = after->left;
    while(temp->val > x && temp->left != NULL){
        temp = temp->left;
    }
    if(temp->left == NULL && temp->val > x) temp->left = r;
    else if(temp->val < x)

} 
TreeNode* buildTreeeee(vector<int> &A){
    int root = 0,last;
    TreeNode* root = new TreeNode(A[0]);
    TreeNode* lastt = root;
    parent[root] = NULL;
    for(int i=1;i<A.size();i++){
        last = i-1;
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
TreeNode* Solution::buildTree(vector<int> &A) {
    unordered_map<TreeNode*,TreeNode*> parent;
    int root = 0,last;
    TreeNode* root = new TreeNode(A[0]);
    TreeNode* lastt = root;
    parent[root] = NULL;
    for(int i=1;i<A.size();i++){
        last = i-1;
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
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output root pointer of tree.
 */
treenode* buildTree(int* A, int n1) {



}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
