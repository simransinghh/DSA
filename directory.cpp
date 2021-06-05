string Solution::simplifyPath(string A) {
// /a/./b/../../c/
    int i =0;
    string ans;
    stack<int> s;
    while(i<A.length()){
        if(s.empty() && A[i]=='/'){
            s.push(i);
            i++;
        }
        else if(A[i]=='/' && A[s.top()] != A[i] && i<A.length()-1){
            s.push(i);
            i++;
        }
        else if(i<A.length()-1 && A[i]=='.' && A[i+1]=='.'){
            s.pop();
            while(!s.empty() && A[s.top()] != '/'){
                s.pop();
            }
            i = i+2;
        }
        else if(A[i]=='.' || A[i]=='/'){
            i++;
        }
        else{
            s.push(i);
            i++;
        }
    }
    if(s.empty()) ans = "/";
    else if(s.size()>1 && A[s.top()]=='/') s.pop();
    while(!s.empty()){
        ans = A[s.top()] + ans;
        s.pop();
    }
    // if(s.size()>1 && A[s.top()]=='/') s.pop();
    return ans;

}
