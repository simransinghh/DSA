int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size(),ans=INT_MIN;
    vector<vector<int>> sums(n,vector<int>(m,0));
    for (int i=n-1;i>=0;--i) {
        for (int j=m-1;j>=0;--j) {
            sums[i][j]=((i+1<=n-1)?sums[i+1][j]:0)+((j+1<=m-1)?sums[i][j+1]:0)+(A[i][j])-((i+1<=n-1 and j+1<=m-1)?sums[i+1][j+1]:0);
            ans=max(ans,sums[i][j]);
        }
    } 
    return ans;
}
