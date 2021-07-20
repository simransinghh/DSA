int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size(),m = A[0].size();
    vector<vector<int> dp(n,vector<int>(m,INT_MAX));
    dp[n-1][m-1] = A[n-1][m-1]*(-1);
    if(A[n-1][m-1]<0) dp[n-1][m-1]++;
    for(int i = m-2;i>=0;i--){
        if(dp[n-1][i+1] <= 0){
             dp[n-1][i] = A[n-1][i]*(-1);
             if(A[n-1][i]<0) dp[n-1][i]++;
        }
        else dp[n-1][i] = A[n-1][i]*(-1) + dp[n-1][i+1]; 
    }
    for(int i = m-2;i>=0;i--){
        if(dp[i+1][m-1] <= 0){
             dp[i][m-1] = A[i][m-1]*(-1);
             if(A[i][m-1]<0) dp[i][m-1]++;
        }
        else dp[i][m-1] = A[i][m-1]*(-1) + dp[i+1][m-1]; 
    }
    for(int i = n-2;i>=0;i--){
        for(int j = m-2;j>=0;j--){
            int mini = min(dp[i+1][j],dp[i][j+1]);
            if(mini < 0){
                mini = 0; 
                dp[i][j] = A[i][j]*(-1);
                if(A[i][j]<0) dp[i][j]++;
            }
            else dp[i][j] = A[i][j]*(-1) + mini; 
        }
    }
    return dp[0][0];
}
