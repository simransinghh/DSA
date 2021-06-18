vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> sol;
    unordered_map<string , vector<int>>mp;
    int n = A.size();
    string temp;
    for(int i = 0 ; i < n ; i++){
        temp = A[i];
        sort(temp.begin() , temp.end());
        mp[temp].push_back(i+1);
    }
    auto it = mp.begin();
    while(it != mp.end()){
        sol.push_back ( it->second);
        it++;
    }
    return sol;

}
