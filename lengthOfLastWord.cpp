int Solution::lengthOfLastWord(const string A) {
    int s = 0;
    int e = A.length()-1;
    for(int i = 0;i < A.length(); i++){
        if(A[i]==' ' && A[i+1] != ' ' && i<A.length()-1){
            s = i+1;
        }
        if(A[i]==' ' && A[i-1] != ' '){
            e = i-1;
        }
    }
    if(A[A.length()-1] != ' ') e = A.length()-1;
    return e-s+1;
}
