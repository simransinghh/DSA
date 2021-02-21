class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }
        int slen = s.length(); 
        int tlen = t.length(); 

        unordered_map<char,int> tt;

        for(int i=0 ; i < tlen ; i++)
        {
            tt[t[i]]++;
        }
        pair<int,int> minn(0,INT_MAX);
        for(int i = 0 ; i <= slen ; i++){
            unordered_map<char,int> ss;
            int j=i;
            bool satisfied = false;
            for(j;j<slen;j++){
                if(tt.find(s[i])==tt.end()){
                    break;
                }
                //check effect of this break on outer forloop statements after
                else{
                    ss[s[j]]++;
                    if(!satisfied){
                        satisfied = true;
                        for (auto k : tt){
                            if(ss[k.first]<tt[k.first]){
                                satisfied = false;
                            }
                        }
                        
                    }
                    if(satisfied){
                        int newl = j-i;
                        int oldl = minn.second-minn.first;
                        int l = min(newl,oldl);
                        if(l==newl){
                            minn.first=i;
                            minn.second=j;
                            break;
                        }
                    }
                }
            }    
        }
        if(minn.second==INT_MAX){
            return "";
        }
        return s.substr(minn.first,minn.second-minn.first+1);

    }
};
