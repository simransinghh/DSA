vector<int> Solution::findPerm(const string A, int B) {
    int l = 1;
    int r = B;
    vector<int> ans;
    for(int i=0;i<B-1;i++){
        if(A[i]=='I'){
            ans.push_back(l);
            l++;
        }else{
            ans.push_back(r);
            r--; 
        }
    }
    
}
