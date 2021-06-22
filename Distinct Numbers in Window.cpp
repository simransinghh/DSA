vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    if(B>A.size())
        return ans;
    unordered_map<int,int> map;
    for(int i=0;i<B;i++){
        map[A[i]]++;
    }
    ans.push_back(map.size());
    for(int i=B;i<A.size();i++){
        int temp = A[i-B];
        map[temp]--;
        if(map[temp]==0){
             map.erase(temp);
             map[A[i]]++;
             ans.push_back(map.size());
        }
        else{
            map[A[i]]++;
            ans.push_back(map.size());
        }
    }
    return ans;
}
