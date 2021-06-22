vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
        int maxsum = INT_MIN;
        int n = A.size();
        vector<int> a;
        priority_queue<int> g;
        for(int i = 0;i<n;i++){
                for(int j=0;j<n;j++){
                        int x = A[i] + B[j];
                        g.push(x);
                }
        }
        int i = 0;
        while(i<n && !g.empty())
                a.push_back(g.top());
                g.pop();
                i++;
        }
        return a;
}
