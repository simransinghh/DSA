vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    priority_queue<int> pq;
    for(int i: A) pq.push(i);
    while(B--){
        int ans = pq.top(); pq.pop();
        res.push_back(ans);
    }
    return res;
}
