vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> a;
    vector<int> ans;

    for (int i=0; i<A.size(); i++){
        a.push_back(A[i]);
    }
    
    sort(a.begin(),a.end());
    int n = A.size();
    int aa = -1, bb = -1;
    for (int i=0; i<n; i++){
        if(aa == -1 && a[i] != A[i]){
            aa = i;
        }
        if(bb == -1 && a[n-i-1] != A[n-i-1]){
            bb = n-i-1;
        }
        if(aa != -1 && bb != -1){
            ans.push_back(aa);
            ans.push_back(bb);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;

}
