string Solution::solve(string A) {
    string ans;
    int s = 0;
    int e = A.length()-1;
    bool space = false;
    for(int i = 0;i < A.length(); i++){
        if(A[i]==' ' && A[i-1] != ' ' && i>0){
            e = i-1;
            if(space){
                ans = A.substr(s,e-s+1) + " " + ans;
            }else{
                ans = A.substr(s,e-s+1) + ans;
            }
            space = true;
        }
        if(A[i]==' ' && A[i+1] != ' ' && i<A.length()-1){
            s = i+1;
        }
    }
     if(A[A.length()-1] != ' ') {
         e = A[A.length()-1];
         ans = A.substr(s,e-s+1) + " " + ans;
    }
    if(ans[0]==' ') ans = ans.substr(1);
    if(ans[ans.length()-1] == ' ') ans = ans.substr(0,ans.length()-1);
    return ans;
}
