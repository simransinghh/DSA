int helper(TreeNode * A,int &ans)
{
    if(!A) return 0;
    int l = helper(A->left,ans);
    int r = helper(A->right,ans);
    ans = max(ans,max(l+r+A->val,max(l,max(r,A->val))));
    return max(A->val,A->val+max(l,r));
}

void maxNode(TreeNode * A, int & ans)
{
    if(!A) return;
    maxNode(A->left,ans);
    ans = max(A->val,ans);
    maxNode(A->right,ans);
}

int Solution::maxPathSum(TreeNode* A) 
{
    int ans = 0;
    helper(A,ans);
    if(ans ==0)
    {
        ans = INT_MIN;
        maxNode(A,ans);
    }
    return ans;
}
