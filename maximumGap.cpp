int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    vector<pair<int,int>> s;
    
    for(int i = 0;i<n;i++){
        s.push_back(make_pair(A[i],i));   
    }
    sort(s.begin(),s.end());
    int ans = 0;
    int f = 0;
    for(int i=1;i<n;i++){
        if(s[f].second>s[i].second){
            f = i;
            continue;
        }
        int x = s[i].second-s[f].second;
        ans = max(x,ans);
    }
    return ans;
}
