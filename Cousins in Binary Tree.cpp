void dfs(TreeNode* root,int parent,int depth,unordered_map<int, pair<int, int>> &mp)
{
if(root==NULL)
{
return;
}
mp[root->val] = {depth, parent};
dfs(root->left,root->val,depth+1,mp);
dfs(root->right,root->val,depth+1,mp);
}
vector<int> Solution::solve(TreeNode* A, int B) {
vector<int> ans;
unordered_map<int, pair<int, int>> mp;
dfs(A,0,-1,mp);
int dep_b=mp[B].first;
int par_b=mp[B].second;
for(auto &[a,b]:mp)
{
if(b.first==dep_b && b.second!=par_b)
{
ans.push_back(a);
}
}
return ans;
}
