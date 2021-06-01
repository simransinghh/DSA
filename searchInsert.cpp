int Solution::searchInsert(vector<int> &A, int B) {
    if(B <= A[0]) return 0;
    int r = A.size();
    if(B > A[r-1]) return r;
    int st = 0;
    int end = r-1;
    int ans = -1;
    while(st<=end){
        int mid = (st+end)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]>B && A[mid-1]<B) return mid;
        else if(A[mid]<B){
            st = mid + 1;
        }
        else if(A[mid]>B && A[mid-1]>B) end = mid - 1;
        else end = mid-1;
    }
    return r;
}
