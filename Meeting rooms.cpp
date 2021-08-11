Solution::solve(vector<vector<int> > &A) {
    
    int ans = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back({A[i][1],-1});
        v.push_back({A[i][0],1});
    }
    
    sort(v.begin(),v.end());
    
    int c=0;
    for(int i=0;i<v.size();i++)
    {
        c = c + v[i].second;
        if(c>ans)
        ans=c;
    }
    
    
    return ans;
    
}
