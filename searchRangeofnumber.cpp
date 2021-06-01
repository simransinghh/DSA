vector<int> Solution::searchRange(const vector<int> &A, int B) {

    int r = A.size();
    int st = 0;
    int end = r-1;
    vector<int> ans={-1,-1};
    while(st<=end){
        int mid = (st+end)/2;
        if(A[mid]==B){
            if(A[mid+1] != B && ans[1] == -1) ans[1] = mid;
            else if(A[mid-1] != B && ans[0] == -1) {
                ans[0] = mid; 
                break;
            }
            else{
                end = mid -1;
            }
        }
        else if(A[mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    st = ans[0];
    end  = r-1;
    if(ans[0] == -1) return ans;
    else if(ans[0] == ans[1]) return ans;
     while(st<=end){
        int mid = (st+end)/2;
        if(A[mid]==B){
            if(mid==end){
                ans[1] = mid;
                return ans;
            }
            if(A[mid+1] != B && ans[1] == -1){
                 ans[1] = mid;
                 break;
            }
            else{
                st = mid + 1;
            }
            
        }
        else if(A[mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    return ans;
}
