int Solution::solve(vector<int> &A, int B) {
        int sum = 0;
        priority_queue<int> pq;
        for(int i=0;i<A.size();i++) pq.push(A[i]);
        while(B>0 && !pq.empty()){
                int a = pq.top();
                pq.pop();
                sum += a;
                if(a>1) pq.push(a-1);
                B--;
        }
        return sum;
}
