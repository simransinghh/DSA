bool ispalindrome(string str)
{
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}
void part(string A,int idx,vector<string> a,vector<vector<string>> & ans){
        if(idx==A.length()){
                ans.push_back(a);
                return;
        }
        //check while
        int len = 1;
        while(len<=A.length() && len+idx<=A.length()){
                string s = A.substr(idx,len);
                bool y = ispalindrome(s);
                if(y){
                        a.push_back(s);
                        part(A,idx+len,a,ans);
                        a.pop_back();
                }
                len++;
        }
        return;

}


vector<vector<string>> Solution::partition(string A) {
     vector<vector<string>> ans;
     vector<string> a;
     part(A,0,a,ans);  
     return ans; 

}
