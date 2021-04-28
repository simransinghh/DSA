string Solution::multiple(int A) {
    queue<string> q;
    q.push("1");
    int visit[A]={0};
    while(!q.empty()){
        string x = q.front();
        q.pop();
        int x1;
  	    stringstream ( x ) >> x1;
        int rem = x1%A;
        if(rem == 0){
            return x;
        }
        if(!visit[rem]){
            visit[rem]=1;
            q.push(x + '0');
            q.push(x + '1');
        }
    }
}
