Solution::solve(int A)
{
    long long int dp[A+1];
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    for(int i=3;i<=A;i++)
    {
        if(i%2==1)
        dp[i]=0;
        else
        dp[i]=((dp[i-2]*4)%1000000007-dp[i-4]%1000000007+1000000007)%1000000007;
    }
    return dp[A];
}
