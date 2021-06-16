string phone[10] = { "0",   "1",   "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> Solution::letterCombinations(string A) {
        vector<string> w;
        vector<string> ans;

        if(A.empty()) return w;
        // cout<<"*"<<endl;
                int x = A[0]-'0';
                string h = phone[x];
                A.erase(0,1);
                // cout<<x<<" "<<h<<" "<<A<<endl;
                w = letterCombinations(A);
                if(w.empty()){
                    // cout<<"empty";
                        for(int j=0;j<h.length();j++){
                                string s ="";
                                s = s + h[j];
                                // cout<<s<<" ";
                                ans.push_back(s);
                        }
                }
                else{
                        for(int k=0;k<w.size();k++){
                            string z = w[k];
                                for(int j=0;j<h.length();j++){
                                        string s = h[j] + z;
                                        ans.push_back(s);
                                        // cout<<endl<<z<<s<<endl;
                                }
                        }
                }
        sort(ans.begin(),ans.end());
        return ans;
}
