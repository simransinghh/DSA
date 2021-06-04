int Solution::removeElement(vector<int> &A, int B) {

    int n = A.size();
    int j = 0,i = 0;
    // cout<<n;
    while(j<n && i<n){
        // if(A[i]!=B){ 
        //     i++;
        //     continue;
        // }
        // cout<<i<<" "<<j<<" "<<endl;
        while(A[j]==B) j++;
        // cout<<j<<" "<<A[j]<<" ";
        if(j<n){
            A[i] = A[j];
        // cout<<i<<" "<<A[i]<<endl;
        // cout<<"---------"<<endl;
            i++;
            j++;
        }
    }
    return i;
}
