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
