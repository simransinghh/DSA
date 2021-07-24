
int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0)
       return 0;
    int n = A.size(), m = A[0].size();
    if(n==0 || m==0) return 0;
    vector<vector<int> > dp(n,vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0) dp[i][j] = A[i][j];
            else dp[i][j] = dp[i-1][j] + A[i][j];
        }
    }
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            unordered_map<int,int> zeros;
            int sum = 0;
            for(int k=0;k<m;k++){
                int curr;
                if(i==0) curr = dp[j][k];
                else curr = dp[j][k] - dp[i-1][k];
                sum += curr;
                //  cout<<i<<" "<<j<<" "<<k<<" "<<curr<<" "<<sum;
                auto it = zeros.find(sum);
                if(sum == 0){
                    count++;
                    // cout<<"zeroooo";
                }
                if(it != zeros.end()){
                    count += zeros[sum];
                    // cout<<"nonzeroo";
                }
                zeros[sum]++;
                cout<<endl;
            }
        }
     }
    //  cout<<endl;
    return count;
}
