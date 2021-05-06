int Solution::repeatedNumber(const vector<int> &A) {
    
    vector v(A.size(),0);
    for (int i=0;i<A.size();i++){
        v[A[i]]+=1;
        if (v[A[i]]!=1){
            return A[i];
        }
    }
    return -1;
}
