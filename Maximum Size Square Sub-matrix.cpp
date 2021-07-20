int Solution::solve(vector<vector<int> > &A) {
int n = A.size(),m=A[0].size();

int dp[n][m];
memset(dp,0,sizeof(dp));

int ans=INT_MIN;
for(int i=n-1;i>=0;i--)
{
    for(int j=m-1;j>=0;j--)
    {
        if(i==n-1 or j==m-1)
        dp[i][j]=A[i][j];
        else
        {
            if(A[i][j]!=0)
            dp[i][j]=1 + min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
        }
        
        ans= max(ans,dp[i][j]);
    }
    
}

return ans*ans;
}
