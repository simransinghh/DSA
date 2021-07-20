#include <bits/stdc++.h>
using namespace std;


int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return -1;
    if(A[0].size() == 0) return -1;
    vector<vector<bool>> mark(A.size(), vector<bool>(A[0].size(), false));
    queue<pair<int, int>> q;
    int r = 0, c = 0;
    q.push({0, 0});
    mark[0][0] = true;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if(r + 1 < A.size() && A[r + 1][c] >= A[r][c] && !mark[r + 1][c]) {
            q.push({r + 1, c});
            mark[r + 1][c] = true;
        }
        if(c + 1 < A[0].size() && A[r][c + 1] >= A[r][c] && !mark[r][c + 1]) {
            q.push({r, c + 1});
            mark[r][c + 1] = true;
        }
    }
    if(r == A.size() - 1 && c == A[0].size() - 1) return r + c + 1;
    else return -1;
    //wrong qn statement. hence, soln to that.
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(),m=A[0].size();
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;

        }
    }
}


int Solution::solve(vector<vector<int> > &A) {
int n = A.size(),m=A[0].size();

int dp[n][m];
memset(dp,0,sizeof(dp));

int ans=INT_MIN;
for(int i=n-1;i>=0;i--)
{
    for(int j=m-1;j>=0;j--)
    {
        if(i==n-1 or j==m-1)
        dp[i][j]=A[i][j];
        else
        {
            if(A[i][j]!=0)
            dp[i][j]=1 + min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
        }
        
        ans= max(ans,dp[i][j]);
    }
    
}

return ans*ans;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> dp(n,vector<int>(n,0));
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


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
