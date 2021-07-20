int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n<=2) return n;

    vector<unordered_map<int, int>> diff(n); 

    int ans = 2;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int tempDiff = A[i] - A[j];
            if(diff[j].find(tempDiff)!=diff[j].end()){
                diff[i][tempDiff] = diff[j][tempDiff]+1;
                ans = max(ans, diff[j][tempDiff]+1);
            } else {
                diff[i][tempDiff] = 2;
            }
        }
    }
    return ans;
}
