int Solution::braces(string A) {
    int i =0;
    stack<int> s;
    while(i<A.length()){
        if(A[i]==')'){
            if(s.empty()) return 1;
            else if(A[s.top()] == '(') return 1;
            else{
                bool x = true;
                while(!s.empty() && A[s.top()] != '('){
                    if(A[s.top()] == '+' || A[s.top()] == '-' || A[s.top()] == '*' || A[s.top()] == '/') x = false;
                    s.pop();
                }
                if(s.empty() || x) return 1;
                else s.pop();
            }
        }
        else{
            s.push(i);
        }
        i++;
    }
    if(!s.empty()) return 0;
    return 0;
}
