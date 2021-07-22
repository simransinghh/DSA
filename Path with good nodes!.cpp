int dfshelper(vector<int> a,vector<int> b[],int root,int c,int parent){
    if(c<0) return 0;
    if(b[root].size()==1){
        return 1;
    }
    int ans = 0;
    for(int x:b[root]){
        if(x==parent) continue; 
        ans += dfshelper(a,b,x,c-a[x-1],root);
    }
    // cout<<root<<" "<<ans<<endl;
    return ans;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    vector<int> adj[A.size()+1];
     for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    return dfshelper(A,adj,1,C-A[0],-1);

}
