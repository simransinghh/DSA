vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int dxa = 0;
    int dxb = 0;
    vector<int> ans;
    while(dxb<B.size() && dxa<A.size()){
        if(A[dxa]==B[dxb]){
            ans.push_back(A[dxa]);
            dxa++;
            dxb++;
        } 
        else if(A[dxa]>B[dxb]) dxb++; 
        else dxa++;
    }
    return ans;

}
