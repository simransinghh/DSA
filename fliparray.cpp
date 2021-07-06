int Solution::solve(const vector<int> &A) {
    int n = A.size();
    long long int S = 0;
    for (int i: A) S += i;
    S /= 2;
    long long int dp[n+1][S+1];
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) dp[i][0] = 0;
    for (int j=1; j<=S; j++) dp[0][j] = INT32_MAX;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=S; j++) {
            if (A[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-A[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if (dp[n][S] == INT32_MAX) {
        for (int j=0; j<=S; j++) {
            if (dp[n][j] < INT32_MAX) dp[n][S] = dp[n][j];
        }
    }
    return dp[n][S];
}
