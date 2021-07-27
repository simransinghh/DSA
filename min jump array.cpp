int Solution::jump(vector<int> &A) {
    int n=A.size();
    if(n==1)
        return 0;
    int max_i1=0,max_i2=0,c=0;
    for(int i=0;i<n;i++){
        if(i>max_i2)
            return -1;
        if(i>max_i1){
            c++;
            max_i1=max_i2;
        }
        max_i2=max(max_i2,A[i]+i);    
        
    }
    return c;
}
