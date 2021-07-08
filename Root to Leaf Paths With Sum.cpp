void help(TreeNode* A,int B,vector<int> cur,vector<vector<int> > &ans,int value)
{
if(A==NULL)
{
return;
}
if(A->left==NULL && A->right==NULL && value==B )
{
cur.push_back(A->val);
ans.push_back(cur);
return;
}
if(A->left==NULL && A->right==NULL && value!=B )
{
return;
}
cur.push_back(A->val);
if(A->left)
{
help(A->left,B,cur,ans,value+A->left->val);
}
if(A->right)
{
help(A->right,B,cur,ans,value+A->right->val);
}

}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {

vector<vector<int> > ans;
vector<int> cur;
if(A==NULL)
{
    return ans;
}
int value=A->val;
help(A,B,cur,ans,value);
return ans;
}
