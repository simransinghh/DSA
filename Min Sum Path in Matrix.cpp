int Solution::minPathSum(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size(), dp[m][n];
    for(int i=m-1; i>=0; i--)
        for(int j=n-1; j>=0; j--)
            if(i==m-1 && j==n-1) dp[i][j] = A[i][j];
            else if(i==m-1) dp[i][j] = A[i][j] + dp[i][j+1];
            else if(j==n-1) dp[i][j] = A[i][j] + dp[i+1][j];            
            else dp[i][j] = A[i][j] + min(dp[i+1][j], dp[i][j+1]);
    return dp[0][0];
}
