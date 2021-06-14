vector<vector<int>> Solution::subsets(vector<int> &A) {
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        if(A.size()==0) {
            ans.push_back(A);
            return ans;
        }
        if(A.size()==1){
                vector<int> h = {A[0]};
                vector<int> g = {};
                ans.push_back(g);
                ans.push_back(h);
                return ans;

        }
        int first = A[0];
        A.erase(A.begin());
        ans = subsets(A);
        int q = ans.size();
        for(int i = 0;i<q;i++){
                vector<int> temp = ans[i];
                temp.insert(temp.begin(),first);
                ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
}
