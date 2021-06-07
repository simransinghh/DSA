int Solution::trap(const vector<int> &A) {
    stack<int>s;
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        while(!s.empty() && A[i] > A[s.top()])
        {
            int height= A[s.top()];
            s.pop();
            if(s.empty()) break;
            int distance=i-1-s.top();
            int min_height=min(A[s.top()],A[i])-height;
            ans+=distance*min_height;
        }
        s.push(i);
    }
    return ans;
}
