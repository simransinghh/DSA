vector<int> Solution::solve(vector<int> &A, int B) {
        vector<int> ans;
        A.sort(A.begin(),A.end(),greater<int>());
        for(int i=0;i<B;i++){
                ans.push_back(A[i]);
        }
        return ans;
}
