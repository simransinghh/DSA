int Solution::nchoc(int n, vector<int> &v){
    priority_queue<int> pq;

    for(int i=0;i<v.size();i++)
    {
        pq.push(v[i]);
    }
    long long sum=0;

    while(n>0)
    {
        int temp=pq.top();
        int num=pq.top();
        sum=(sum+num);
        pq.pop();
        pq.push(num/2);
        n--;
}
    int temp=sum%1000000007;
    return temp;
}
