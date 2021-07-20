int Solution::solve(vector<int> &a, int sum) {

int n = a.size();

bool dp[n+1][sum+1];

for(int i=0; i<=sum; i++)
	dp[0][i] = false;

for(int i=0; i<=n; i++)
	dp[i][0] = true;

for(int i=1; i<=n; i++){
	for(int j=1; j<=sum; j++){
		if(j<a[i-1])
			dp[i][j] = dp[i-1][j];

		else
			dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
	}
}

return dp[n][sum];
}
