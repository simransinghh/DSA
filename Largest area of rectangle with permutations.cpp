int maxarea(vector<int> A){
    sort(A.begin(),A.end(),greater<int>());
    int ans = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(i<n-1 && A[i]==A[i+1]){
            continue;
        }
        if(A[i]==0) break;
        ans = max(ans,A[i]*(i+1));
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {

    int ans = maxarea(A[0]);
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] != 0) A[i][j] = A[i-1][j] + 1;
        }
        // cout<<ans<<" ";
        ans = max(ans,maxarea(A[i]));
    
        // cout<<ans<<endl;
    }
    return ans;

}
