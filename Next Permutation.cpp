vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    if(n==1){
        return A;
    }
    bool asec = false;
    int pt = -1;
    int i=n-1;
    for(i;i>0;i--){
        if(A[i]>A[i-1]){
            pt = i;
            asec = true;
            break;
        }
    }
    if(!asec){
        sort(A.begin(), A.end()); 
        return A;
    }
    if(pt==n-1){
        swap(A[i],A[i-1]);
    }
    else{
        int minidx = pt;
        for(int i=pt;i>n;i++){
            if(A[pt+1]<A[i] && A[minidx]>A[i]){
                minidx = i;
            }
        }
        swap(A[pt+1],A[minidx]);
        sort(A.begin()+pt, A.end());
        
    }
    return A;
}
