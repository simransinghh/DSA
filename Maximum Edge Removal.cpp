void dfs(int st,vector<int> &vis,vector<int> &count,vector<int> adj[])
{
    vis[st]=1;
    
    for(auto it: adj[st])
    {
        if(!vis[it])
        {
       dfs(it,vis,count,adj);
           count[st]+=count[it]+1;
        }
    }
    count[st]+=0;
  
}


int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
        
    }
    vector<int> count(A,0);
    vector<int> vis(A,0);
    int res=0;
    dfs(0,vis,count,adj);
    
    for(int it=0;it<A;it++)
    {
        if(count[it]%2!=0 && it!=0)res++;
    }
    
    return res; 
}
