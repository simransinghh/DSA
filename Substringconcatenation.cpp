vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    if(B.size()==0) return ans;
    int l = B[0].size();
    if(l==0) return ans;
    
    unordered_map<string, int> m;
    for(auto x : B) m[x]++;
    
    for(int i=0; i<A.size(); i++){
        int j = i;
        int count = 0;
        while(m[A.substr(j, l)]){
            m[A.substr(j, l)]--;
            count++;
            if(count==B.size()){
                ans.push_back(i);
                break;
            }
            j += l;
        }
        j = i;
        while(count--){
            m[A.substr(j, l)]++;
            j += l;
        }
    }
    return ans;
}
