int Solution::coinchange2(vector<int> &A, int n) {

long long mod = 1000007;
long long  dp[n+1];
memset(dp,0,sizeof(dp));
dp[0]=1;
for(int i=0;i<A.size();i++)
{
    for(int j=A[i];j<=n;j++)
    {   
        
        dp[j]= dp[j]%mod + dp[j-A[i]]%mod;
    }
    
}

return dp[n]%mod;
}
