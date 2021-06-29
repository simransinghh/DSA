void inorder(TreeNode* A, vector<int> &ans)
{
    if(A==NULL) return;
    inorder(A->left,ans);
    ans.push_back(A->val);
    inorder(A->right,ans);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> ans;
    inorder(A,ans);
    map<int,int>map;
    for(int i=0;i<ans.size();i++)
    {
        int k=B-ans[i];
        if(map.find(k)!=map.end()) return 1;
        else if(map.find(k)==map.end()) map[ans[i]]=i;
    }
    return 0;
}
