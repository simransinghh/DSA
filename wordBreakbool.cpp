unordered_map<string,bool> m;

int solve(string A, unordered_set<string> &st)
{
    if(A == "") return 1;
    if(m.count(A)) return m[A];
    
    for(int i = 0; i < A.size(); i++){
        string sub = A.substr(0, i+1);
        if(st.find(sub) != st.end()) {
            if(solve(A.substr(i+1), st)) return m[A] = 1;
        }
    }
    return m[A]= 0;
}


int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> st;
    for(auto &a: B) st.insert(a);
    m.clear();
    return solve(A, st);
}
