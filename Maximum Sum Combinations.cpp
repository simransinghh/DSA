vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>res;
    priority_queue <int, vector<int>, greater<int> > pq;
    sort(A.begin(), A.end(),greater<int>()); 
    sort(B.begin(), B.end(),greater<int>());
    int x = 0;
    for(int i=0; i<A.size(); i++) {
            for(int j = 0;j<B.size();j++){
                int sum  = A[i]+B[j];
                if(x==C){
                        if(sum > pq.top()){
                                pq.pop();
                                pq.push(sum);
                        }
                        else break;
                }
                else{
                      pq.push(sum);  
                      x++;
                }
            }
    }
    for(int i = 0;i<C;i++){
            res.push_back(pq.top());
            pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
