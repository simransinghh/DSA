int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size();
    int c = A[0].size();
    int st = 0;
    int end = r-1;
    int thiss = -1;
    while(st<=end){
        int mid = (st+end)/2;
        if(A[mid][0]==B) return 1;
        else if(A[mid][0]>B) end = mid-1;
        else if(mid == end){
            thiss = mid;
            break;
        }
        else{
            if(A[mid+1][0] > B){
                thiss = mid;
                break;
            }
            st = mid + 1;
        }
    }
    if(thiss == -1) return 0;
    st = 0;
    end = c-1;
    while(st<=end){
        int mid = (st+end)/2;
        if(A[thiss][mid]==B) return 1;
        else if(A[thiss][mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    return 0;
}
// A : 
// [
//   [2, 9, 12, 13, 16, 18, 18, 19, 20, 22]
//   [29, 59, 62, 66, 71, 75, 77, 79, 97, 99]
// ]
// B : 45
