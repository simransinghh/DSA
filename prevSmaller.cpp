vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> pro(n,-2);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            pro[i] = -1;
            s.push(i);
        }
        //check eqaulity conditions and empty
        else if(A[i]<=A[s.top()]){
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()) pro[i] = -1;
            else {
                pro[i] = A[s.top()];
            } 
            s.push(i);
        }
        else{
            pro[i] = A[s.top()];
            s.push(i);
        }     
    }
    while(!s.empty()){
        if(pro[s.top()] == -2) pro[s.top()] = -1;
        s.pop();
    }
   
    return pro;


}
