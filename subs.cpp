vector<vector<int> > Solution::subsets(vector<int> &A) {
sort(A.begin(), A.end());
int sz;
vector<vector<int>> ans = {};
for (int i=A.size()-1; i>=0; --i)  {
    sz=ans.size();
    for (int j=0; j<sz; ++j)    {
        vector<int> t = ans[j];
        t.push_back(A[i]);
        ans.push_back(t);
    }
    ans.push_back({A[i]});
}
ans.push_back({});
// flipping vectors in ans (horizontally)
for (int i=0; i<ans.size(); ++i)
    reverse(ans[i].begin(), ans[i].end());
// flipping vectors in ans (vertically)
reverse(ans.begin(), ans.end());
return ans;
}
