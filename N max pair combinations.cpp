vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
        int n=A.size();
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        priority_queue<int, vector<int>,greater<int>> pq;
        vector<int> ans;
        for(int i=0;i<A.size();i++)
                for(int j=0;j<B.size();j++)
                {
                        int sum=A[i]+B[j];
                        if(i==0) pq.push(sum);
                        else if(sum>pq.top()){
                                pq.pop();
                                pq.push(sum);
                        }
                        else break;
                }
        while(n--){
                ans.push_back(pq.top());
                pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
