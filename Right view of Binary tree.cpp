void kuckbhi(TreeNode* root,vector<int> &a,int level){
    if(root==NULL) return;
    if(level>a.size()){
        a.push_back(root->val);
    }
    kuckbhi(root->right,a,level+1);
    kuckbhi(root->left,a,level+1);
    return;
}
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    ans.push_back(A->val);
    kuckbhi(A,ans,1);
    return ans;
}
