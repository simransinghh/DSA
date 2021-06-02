int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    if(B<0) B = B*(-1);
    int i = 0,l = 1;
    while(l<A.size()){
        if(A[l] - A[i] == B || A[i] - A[l] == B) return 1;
        else if(A[l] - A[i] < B) l++;
        else if(A[l] - A[i] > B) i++;
        if(i==l) l++;
    } 
    return 0;
}
