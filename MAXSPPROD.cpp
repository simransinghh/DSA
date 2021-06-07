int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<int> pro(n,-1);
    stack<int> s;
    int max = 0;
    for(int i=0;i<n;i++){
        if(s.empty()){
            pro[i] = 0;
            s.push(i);
        }
        //check eqaulity conditions and empty
        else if(A[i]>=A[s.top()]){
            while(!s.empty() && A[s.top()]<A[i]){
                int right =i;
                if(pro[s.top()]==-1) pro[s.top()] = right;
                else pro[s.top()] *= right;
                s.pop();
            }
            if(s.empty()) pro[i] = 0;
            else if(A[s.top()] == A[i]){
                int left = pro[s.top()];
                if(pro[i]==-1) pro[i] = left;
                else pro[i] *= left;
            }
            else {
                int left = s.top();
                if(pro[i]==-1) pro[i] = left;
                else pro[i] *= left;
            } 
            s.push(i);
        }
        else{

            int left = s.top();
            if(pro[i]==-1) pro[i] = left;
            else pro[i] *= left;
            s.push(i);

        }
            
    }
    while(!s.empty()){
        pro[s.top()] = 0;
        s.pop();
    }
    sort(pro.begin(), pro.end(), greater<int>());
    return pro[0];
}
