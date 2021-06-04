int Solution::removeDuplicates(vector<int> &A) {
    int j = 1;
    int i = 0;
    int n = A.size();
    if(n==0 || n==1 || n==2) return n;
    while(i<n && j<n){
        // cout<<A[i]<<" "<<i<<","<<A[j]<<" "<<j<<endl;
        if(A[i]==A[j]){ 
            i++;
            j++;
        }
        while(j<n && A[i]==A[j]){
            j++;
        }
        // cout<<A[i]<<" "<<i<<","<<A[j]<<" "<<j<<endl;
        A[++i] = A[j];
        if(j<n-1 && A[j]==A[j+1]) A[++i] = A[++j];
        // cout<<i<<" "<<A[i]<<"   "<<A[i-1]<<endl;
        // cout<<A[i]<<" "<<i<<","<<A[j]<<" "<<j<<endl;
        while(j<n && A[i]==A[j]){
            j++;
        }
        // cout<<A[i]<<" "<<i<<","<<A[j]<<" "<<j<<endl;
        // cout<<"--------"<<endl;
    }
    return i+1;
}
