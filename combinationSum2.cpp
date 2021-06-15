bool combo(vector<int> &A, int B ,vector<vector<int>> &ans, int idx){
        vector<vector<int>> x;
        if(B==0){
                return true;
        }
        if(B<0){
                return false;
        }
        bool f = false;
        for(int i = idx;i<A.size();i++){
                if(i>0 && A[i]==A[i-1] && i != idx) continue;
                if(combo(A,B-A[i],x,i+1)){
                    f = true;
                        if(x.empty()){
                                vector<int> z = {A[i]};
                                ans.push_back(z);
                        }
                        else {
                                for(int j = 0; j < x.size(); j++){
                                x[j].insert(x[j].begin(),A[i]);
                                ans.push_back(x[j]);
                                }
                        }
                }
                x.clear();
        }
        return f;
}


vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    bool a = combo(A,B,ans,0);
    return ans;

}
