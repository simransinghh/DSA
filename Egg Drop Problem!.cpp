int Solution::solve(int A, int B) {
    
vector<vector<int>> dp(A+1,vector<int>(B+1,0));

for(int i=1;i<=B;i++)
    dp[1][i]=i;

for(int i=1;i<=A;i++)
{
    dp[i][1]=1;
}
int low=0,high=0;
for(int i=2;i<=A;i++)
{
    for(int j=2;j<=B;j++)
    {
        if(i>j)             //cosidering worst case scenario
        {    dp[i][j]=dp[i-1][j];
                continue;
        }
        int t=INT_MAX;
        low=1;
        high=j;
        while(low+1<high)
        {
            int mid=(low+high)/2;
            
            if(dp[i-1][mid-1]<dp[i][j-mid])
                low=mid;
            else if(dp[i-1][mid-1]>dp[i][j-mid])
                high=mid;
            else
                high=low=mid;
                
        }
        t=1+min(max(dp[i-1][low-1],dp[i][j-low]),max(dp[i-1][high-1],dp[i][j-high]));
       
        
        dp[i][j]=t;
    }
}


return dp[A][B];
}
