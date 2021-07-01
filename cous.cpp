vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A || A->val==B) return{};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    int noofsiblings = 1;
    bool iffound = false;
    while(!q.empty() && !iffound){
        int temp = noofsiblings;
        while(temp>0){
            TreeNode* t = q.front();
            if(t->left==NULL)
            q.push(t->left);
            q.push(t->right);
            if(t->left->val==B || t->right->val==B){
                iffound = true;
            }
            q.pop();
            temp--;
        }
        if(iffound) break;
        noofsiblings *= 2;
    }
    int now = 0;
    while(!q.empty()){
        if(q.front()->val==B){
            if(now==0){
                q.pop();
                q.pop();
            }else if(now==1){
                ans.pop_back();
                q.pop();
                now=0;
            }
        }
        ans.push_back(q.front()->val);
        if(now==1) now=0;
        else now=1;
    }
    return ans;
}
