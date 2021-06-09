string Solution::solve(string A) {
    string sol;
    queue<char> q;
    int arr[26] = {0}; 
    for(int i = 0;i<A.length();i++){
        int x = A[i] - 97;
        if(arr[x] == 0){
            q.push(A[i]);
        }
        arr[x]++;
        if(q.empty()){
            char c = '#';
            sol.push_back(c);
            continue;
        }
        int y = q.front() - 97;
        if(arr[y]==1){
            sol.push_back(q.front());
        }else{
            q.pop();
            i--;
        }
    }
    while(sol.length()<A.length()){
        if(!q.empty()){
            sol.push_back(q.front());
        }else{
            sol.push_back('#');
        }
    }
    return sol;
// "cxbctvqxq"
}
