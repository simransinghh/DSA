vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B){
    vector<vector<int>> dp=B;
    for(int k=1;k<=A;k++)
    {
        vector<vector<int>> h(B.size(),vector<int>(B[0].size()));
        for(int i=0;i<B.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                h[i][j]=dp[i][j];
                if(i>0)
                    h[i][j]=max(h[i][j],dp[i-1][j]);
                if(i<B.size()-1)
                    h[i][j]=max(h[i][j],dp[i+1][j]);
                if(j>0)
                    h[i][j]=max(h[i][j],dp[i][j-1]);
                if(j<B[0].size()-1)
                    h[i][j]=max(h[i][j],dp[i][j+1]);
            }
        }
        dp=h;
    }
    return dp;
}
