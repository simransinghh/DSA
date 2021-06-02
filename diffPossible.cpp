int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0,l = 1;
    while(l<A.size()){
        if(A[l] - A[i] == B) return 1;
        if(A[l] - A[i] < B) l++;
        if(A[l] - A[i] > B) i++;
        if(i==l) l++;
    } 
    return 0;
}
