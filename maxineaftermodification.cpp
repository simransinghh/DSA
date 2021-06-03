int Solution::solve(vector<int> &A, int B) {
    int o = 0;
    int t = 1;
    int temp = B;
    int maxsize = 0;
    if(A[0]==0 && temp>0) temp--;
    for(o;o<A.size();o++){
 
        while(t<A.size()){
            if(temp>0 && A[t]==0){
                temp--;
                t++;
            }else if(A[t]==1) t++;
            else{
                break;
            }
        }
        
        int x = t-o;
        maxsize = max(maxsize,x);
        if(t==A.size()) return maxsize;
        // else{
        //     if(A[t-1]==0) temp++;
        // }
        while(A[o]==1){
            o++;
        }
        temp++;
        // if(o==t-2){ 
        //     if(A[t]==0) temp++;
        //     t++;
        // }
    }
    return maxsize;
}
