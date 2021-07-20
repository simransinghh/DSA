int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n==1) return A[0][0];
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = A[0][0];
    dp[1][0] = A[0][0] + A[1][0];
    dp[1][1] = A[0][0] + A[1][1];
    int ans = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(i==n-1){
                if(dp[i][j] > ans) ans = dp[i][j];
            }
            else{
                dp[i+1][j] = ((A[i+1][j] + dp[i][j] > dp[i+1][j])? A[i+1][j] + dp[i][j] : dp[i+1][j]);
                dp[i+1][j+1] = ((A[i+1][j+1] + dp[i][j] > dp[i+1][j+1])? A[i+1][j+1] + dp[i][j] : dp[i+1][j+1]);   
            }
        }
    }
    return ans;
}
