int merge(vector<int> &A, int n, vector<int> &temp, int left, int mid, int right){
int i=left, j=mid, k=left;
int inv_count = 0;

    while((i<=mid-1) && (j<=right)){
        if(A[i]<=A[j]){
            temp[k++] = A[i++];
        }
        else{
            inv_count += mid-i;
            temp[k++] = A[j++];
        }
    }
    
    while(i<=mid-1){
        temp[k++] = A[i++];
    }
    
    while(j<=right){
        temp[k++] = A[j++];
    }
    
    for(i=left; i<=right; i++){
        A[i] = temp[i];
    }
    
    return inv_count;
}

int _mergesort(vector<int> &A, int n, vector<int> &temp, int left, int right){
    if(left>=right) return 0;
    int mid = (left+right)/2;
    int inv_count = 0;
    
    inv_count += _mergesort(A, n, temp, left, mid);
    inv_count += _mergesort(A, n, temp, mid+1, right);
    inv_count += merge(A, n, temp, left, mid+1, right);
    
    return inv_count;
}

int mergesort(vector<int> &A, int n){
    vector<int> temp(n);
    return _mergesort(A, n, temp, 0, n-1);
}

int Solution::countInversions(vector<int> &A) {
    int n = A.size();
    int ans = mergesort(A, n);
    return ans;
}
