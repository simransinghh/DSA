vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(!A)
        return ans;
    stack<TreeNode*> s1,s2;
    s1.push(A);
    while(!s1.empty() || !s2.empty()){
        vector<int> t;
        while(!s1.empty()){
            t.push_back(s1.top()->val);
            TreeNode* temp = s1.top();
            s1.pop();
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        if(t.size())
            ans.push_back(t);
        t.clear();
        while(!s2.empty()){
            TreeNode * temp = s2.top();
            s2.pop();
            t.push_back(temp->val);
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
        if(t.size())
            ans.push_back(t);
    }
    return ans;
}
