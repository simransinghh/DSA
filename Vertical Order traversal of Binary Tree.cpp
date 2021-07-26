vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
        map<int,vector<int>> mp;
        vector<vector<int> > ans;
        if(A==NULL) return ans;
        //for Level order traversal
        queue<pair<int, TreeNode*> > q; 
        q.push(make_pair(0,A));
        while(!q.empty())
        {
            int temp=q.front().first;
            TreeNode* tr=q.front().second;
            mp[temp].push_back(tr->val);
            
            if(tr->left) q.push(make_pair(temp-1,tr->left));
            if(tr->right) q.push(make_pair(temp+1,tr->right));
            
            q.pop();
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
    }
