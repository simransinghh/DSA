vector<int> Solution::solve(TreeNode* A) {
    vector<int>res;
    queue<TreeNode*>q;
    q.push(A);
    while(!q.empty())
    {
        int n=q.size();
        vector<int>temp;
        while(n--)
        {
            TreeNode* t=q.front();
            temp.push_back(t->val);
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        if(res.size()==0)
        res=temp;
        else
        res.insert(res.begin(),temp.begin(),temp.end());
    }
    return res;
}
