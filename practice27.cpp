#include <bits/stdc++.h>
using namespace std;

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

int Solution::numDecodings(string A) {
    int N=A.length();
    int dp[N+1];
    for(int i=0; i<=N; i++){
        dp[i]=0;
    }
    dp[0] = 1;
    dp[1] = A[0]=='0' ? 0 : 1;
    for(int i=2; i<=N; i++){
        int oneDigit=stoi(A.substr(i-1,1));
        int twoDigit=stoi(A.substr(i-2,2));
        if(oneDigit>=1){
            dp[i] += dp[i-1];
        }
        if(twoDigit>=10 && twoDigit<=26){
            dp[i] += dp[i-2];
        }
    }
    return dp[N];
}

int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int i = 0;
    if(N == 0) return 0; 
    
    for(i = 1; i<N; i++){
        A[i][0] += min(A[i-1][1], A[i-1][2]); 
        A[i][1] += min(A[i-1][0], A[i-1][2]);
        A[i][2] += min(A[i-1][0], A[i-1][1]);
    }
    
    int ans = min(min(A[i-1][0], A[i-1][1]), A[i-1][2]);
    return ans;
}

Solution::solve(int A)
{
    long long int dp[A+1];
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    for(int i=3;i<=A;i++)
    {
        if(i%2==1)
        dp[i]=0;
        else
        dp[i]=((dp[i-2]*4)%1000000007-dp[i-4]%1000000007+1000000007)%1000000007;
    }
    return dp[A];
}

int maxarea(vector<int> A){
    sort(A.begin(),A.end());
    int ans = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(i<n-1 && A[i]==A[i+1]){
            continue;
        }
        ans = max(ans,A[i]*i+1);
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {

    int ans = maxarea(A[0]);
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(!A[i][j]) A[i][j] = A[i-1][j] + 1;
        }
        ans = max(ans,maxarea(A[i]));
    }
    return ans;

}




vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    ans.push_back(1);
    int i=0,j=0,k=0;
    while(D--){
        int x=min(ans[i]*A,min(ans[j]*B,ans[k]*C));
        if(x==ans[i]*A)
        i++;
        if(x==ans[j]*B)
        j++;
        if(x==ans[k]*C)
        k++;
        ans.push_back(x);
    }
    ans.erase(ans.begin());
    return ans;
}

int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
