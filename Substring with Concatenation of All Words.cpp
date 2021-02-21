class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words[0].length();
        int len = s.length(); 
        int m = words.size();
        int concat = n*m;
        if(len<concat){
            return ans;
        }
        unordered_map<string,int> word;

        for(int i=0 ; i < m ; i++)
        {
            word[words[i]]++;
        }
        for(int i = 0 ; i <= len-concat ; i++){
            unordered_map<string,int> check;
            int j=i;
            for(j;j<i+concat;){
                string sub = s.substr(j,n);
                if(word.find(sub)==word.end()){
                    break;
                }else{
                    check[sub]++;
                    if(check[sub]>word[sub]){
                        break;
                    }
                }
                j+=n;
            }
            if(j==i+concat){
                ans.push_back(i);
            }       
        }
        
        return ans;
                                                                  
    }
};
