vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    // vector<in?> ans(n);
    int l   = A[n-1];
    for(int i = 0; i<n;i++){
        swap(A[i],A[i+1]);
        i++;
    }
    if(n%2 != 0){
        A[n-1]=l;
    }
    return A;
}
