int Solution::sqrt(int A) {
    if(A==0) return 0;
    if(A==1) return 1;
    int start = 1;
    int end = A;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(A/mid < mid){
            end = mid - 1;
        }
        else if(A == mid*mid) {
            return mid;
        }
        else if(A>mid*mid){
            if(A/(mid+1)<(mid+1)){
                return mid;
            }else{
                 start = mid+1;
            }
        }
    }
    return mid;
}

