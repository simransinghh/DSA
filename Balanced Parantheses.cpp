int Solution::solve(string A) {
    int i=0;
    stack<int> s;
    while(i<A.length()){
        if(A[i]==')'){
            if(s.empty()) return 0;
            while(!s.empty() && A[s.top()]!='('){
                s.pop();
            }
            if(s.empty()) return 0;
            else{
                s.pop();
                i++;
            }
        }
        else if(A[i]=='('){
            s.push(i);
            i++;
        }
        else i++;
    }

    if(s.empty()) return 1;
    return 0;
}
