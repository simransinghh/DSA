int Solution::solve(vector<int> &A) {
    stack<int> ihatetnp;
    int minnow = INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i] < minnow){
            // cout<<i<<" "<<A[i]<<" "<<minnow<<endl;
            return 0;
        }
        if(ihatetnp.empty()){
            ihatetnp.push(A[i]);
            continue;
        }
        else if(ihatetnp.top()>=A[i]){
            ihatetnp.push(A[i]);
        }
        else{
            while(!ihatetnp.empty() && ihatetnp.top()<A[i]){
                minnow = ihatetnp.top();
                ihatetnp.pop();
            }
            ihatetnp.push(A[i]);
        }
    }
    return 1;
}
