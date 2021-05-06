int Solution::repeatedNumber(const vector<int> &A) {
    unordered_map<int,int> a;
    int n = A.size();
    for(int i=0;i<n;i++){
        a[A[i]]++;
    }
    for(auto node:a){
        if(node.second > 1){
            return node.first;
        }
    }
    return -1;
}
