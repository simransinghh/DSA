int Solution::solve(int n, int s) {
    int dp[n+1][s+1];
    memset(dp,0,sizeof dp);
    
    for(int i=1;i<=s;i++){
        dp[1][i]=(i<=9);
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=s;j++){
            for(int k=0;k<=9&&j-k>=0;k++){
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=(int)(1e9+7);
            }
        }
    }
    return dp[n][s];
}
