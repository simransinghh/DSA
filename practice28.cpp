#include <bits/stdc++.h>
using namespace std;
int lonsub(vector<pair<int,int>> ss,int index,int lastmin, vector<int>& dp){
    if(dp[index] != -1) return dp[index];
    if(index == ss.size()) return 0;
    if(ss[index].first <= lastmin) return lonsub(ss,index+1,lastmin,dp);
    else dp[index] = max(lonsub(ss,index+1,lastmin,dp),lonsub(ss,index+1,ss[index].second,dp)+1);
    return dp[index];
}

int Solution::solve(vector<vector<int> > &A) {
    vector<pair<int,int>> ss;
    for(int i=0;i<A.size();i++){
        ss.push_back(make_pair(A[i][0],A[i][1]));
    }
    sort(ss.begin(),ss.end());
    vector<int> dp(A.size(),-1);
    int x = lonsub(ss,0,INT_MIN,dp);
     return *max_element(dp.begin(),dp.end());
}


int Solution::solve(vector<vector<int> > &a) {
    vector<int> lis(a.size(),1);
    for(int i=1; i<a.size(); i++)
     for(int j=0; j<i; j++)
        if(a[i][0]>a[j][1]) lis[i]=max(lis[i],lis[j]+1);
    return *max_element(lis.begin(), lis.end());
}

lonsub(vector<pair<int,int>> ss,int index,int lastmin, vector<int>& dp){
    if(dp[index] != -1) return dp[index];
    if(index == ss.size()) return 0;
    if(ss[index].first <= lastmin) dp[index] = lonsub(ss,index+1,lastmin,dp);
    else dp[index] = max(lonsub(ss,index+1,lastmin),lonsub(ss,index+1,(ss[index].second)+1,dp);
    return dp[index];
}

int Solution::solve(vector<vector<int> > &A) {
    vector<pair<int,int>> ss;
    for(int i=0;i<A.size;i++){
        ss.push_back(make_pair(A[i][0],A[i][1]));
    }
    sort(ss.begin(),ss.end());
    vector<int> dp(A.size(),-1);
    return lonsub(ss,0,INT_MIN,dp);
}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
