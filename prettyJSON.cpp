vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;
    int space = 0;
    for(int i = 0;i< A.length() ; i++){
        string a;
        bool nextline = false;
        bool first = true;
        bool isthere = false;
        while(!nextline){
            if((A[i] == '{' || A[i] == '[' || A[i] == ',')&& !isthere){
                if(A[i]==',')space--;
                else{ 
                    for(int j = 0 ; j < space ; j++){
                        a = a + '\t';
                    }
                }
                a = a + A[i];
                space++;
                if(A[i+1] != ',')nextline = true;
                else{
                    i++;
                }
            }
            else if((A[i] == '}' || A[i] == ']') && !isthere){
                space--;
                for(int j = 0 ; j < space ; j++){
                    a = a + '\t';
                }
                a = a + A[i];
                if(A[i+1] != ',')nextline = true;
                else{
                    i++;
                }
            }
            else if(A[i] == '{' || A[i] == '[' || A[i] == '}' || A[i] == ']'){
                nextline = true;
                i--;
            }
            else{
                if(first){
                    for(int j = 0 ; j < space ; j++){
                        a = a + '\t';
                        first = false;
                    }
                }
                isthere = true;
                a = a + A[i];
                if(A[i] == ','){
                    nextline = true;
                }else{
                    i++;
                }
            }
        }
        ans.push_back(a);
    }
    return ans;
}
// A : "{"id":100,"firstName":"Jack","lastName":"Jones","age":12}"

