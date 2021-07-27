int Solution::numTrees(int A) {

int dp[A+1];

for(int i=0;i<=A;i++)
    dp[i]=0;

dp[0]=1;
dp[1]=1;

for(int i=1;i<=A;i++){
    dp[i]=0;
    for(int j=1;j<=i;j++){
        
        dp[i]=dp[i]+dp[j-1]*dp[i-j];
    }
}


return dp[A];
}
