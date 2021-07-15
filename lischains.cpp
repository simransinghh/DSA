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
