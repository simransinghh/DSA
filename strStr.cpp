int Solution::strStr(const string B, const string A) {
        if(A.length()>B.length()) return -1;
        if(A.length()==0 && B.length()==0) return 0;
        if(A.length()==0 && B.length()!=0) return 0;

        if(A.length()==0 || B.length()==0) return -1;
    int j = 0;
    for(int i=0;i<=B.length()-A.length();i++){
        if(B[i] == A[0]){
            int k = i+1;
            j++;
            while(B[k]==A[j] && j<A.length()){
                j++;
                k++;
            }
            if(j<A.length()){
                j = 0;
            }
            else return i;
        }
    }
    return -1;
}
