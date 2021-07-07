bool isPalindrome(string A, int i, int j){
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int Solution::minCut(string A) {
    int n=A.length();
    vector<int>dp(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(isPalindrome(A,j,i)){
                if(j>0) dp[i]=min(dp[i],dp[j-1]+1);
                else dp[i]=0;
            }
        }
    }
    return dp[n-1];
    
}
