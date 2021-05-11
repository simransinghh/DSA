string Solution::longestCommonPrefix(vector<string> &A) {

    int minn = 0;
    int n =  A.size();
    for(int i=1;i<n;i++){
        if(A[minn].length()>A[i].length()){
            minn = i;
        }    
    }
    for(int i=0;i<n;i++){
        A[i] = A[i].substr(0,A[minn].length());
    }
    minn = A[0].length();
    int finall = minn;
    for(int i=0;i<n-1;i++){
        // if(i==0){
        //     A[i+1] = A[i+1].substr(0,minn);
        // }
        A[i+1] = A[i+1].substr(0,finall);
        int x=0,y=minn-1;
        int len = 0;
        while(x<=y){
            int mid = (x+y)/2;
            if(mid == x){
                if(A[i].substr(x,1) == A[i+1].substr(x,1)){
                  x++;
                  len = mid+1;
                  continue; 
                }
                else{
                   y = mid - 1;
                   continue; 
                }
            }
            if(A[i].substr(x,mid-x) == A[i+1].substr(x,mid-x)){
                x = mid;
                len = mid;
                continue;
            }
            else{
                y = mid - 1;
                continue;
            }
        }
        finall = min(len,finall);
    }
    
    return A[0].substr(0,finall);
}
