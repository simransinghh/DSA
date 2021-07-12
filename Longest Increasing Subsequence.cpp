int Solution::lis(const vector<int> &A) {
    int N = A.size();
    int i,j;
    vector<int> LIS(N, 1);
    
    for(i = 1; i<N; i++){
        for(j = 0; j<i; j++){
            if(A[i] > A[j] && LIS[i] <= LIS[j]) LIS[i] = LIS[j]+1;
        }
    }
    return *max_element(LIS.begin(), LIS.end());
}
