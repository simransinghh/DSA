bool isValid(int x,int y,int n,int m){
    return (x>=0 && y>=0 && x<n && y<m);
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    vector<pair<int,int>> adj={{1,0},{0,1}};
    queue<pair<int,int>> q;
    vis[0][0]=1;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> p=q.front();
        int i=p.first,j=p.second;
        q.pop();
        if(i==n-1 && j==m-1)
            return n+m-1;
        for(auto v:adj){
            int x=i+v.first,y=j+v.second;
            if(isValid(x,y,n,m) && !vis[x][y] && A[x][y]>A[i][j]){
                vis[x][y]=1;
                q.push({x,y});
            }
        }
    }
    return -1;
}
