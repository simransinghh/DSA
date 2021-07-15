int dp[100005];
long long int mod = 1e9+7;
int recur(string A,int i){
    if(i==A.size()) return 1;
    if(A[i]=='0') return 0;
    long long int ans = 0;
    if(dp[i]!=-1) return dp[i];
    if(A[i]=='1' || (A[i]=='2' && i+1!=A.size() && A[i+1]<='6' )) ans += recur(A,i+2),ans %= mod;
    ans += recur(A,i+1);
    ans %= mod;
    return dp[i]=ans;
}
int Solution::numDecodings(string A) {
    memset(dp,-1,sizeof(dp));
    return recur(A,0);
}
