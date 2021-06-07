int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    stack<int> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(i);
        }
        else if(A[i]<A[s.top()]){
            while(!s.empty() && A[s.top()]>A[i]){
                int temp = s.top();
                s.pop();
                int w;
                if(s.empty()){
                    w = i;
                }
                else w = i - s.top() - 1;
                int h = A[temp];
                int area = h*w;
                ans = max(ans,area);
            }
            // if(s.empty()) pro[i] = -1;
            // else {
            //     pro[i] = A[s.top()];
            // } 
            s.push(i);
        }
        else{
            // pro[i] = A[s.top()];
            s.push(i);
        }     
    }
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        int w;
        if(s.empty()){
            w = n;
        }
        else w = n - s.top() - 1;
        int h = A[temp];
        int area = h*w;
        ans = max(ans,area);
        // int h = A[s.top()];
        // int w = n - s.top();
        // int area = h*w;
        // ans = max(ans,area);
        // s.pop();
    }
   
    return ans;
}
