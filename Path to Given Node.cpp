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
