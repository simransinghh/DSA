int dp[1000][1000];
int dfs(int ind, string s, int k)
{
  if(ind==s.size() && k==0)
    return 0;
  if(k<=0)
    return -1;
  if(dp[ind][k]!=-1)
    return dp[ind][k];
  int w=0,b=0,mini=INT_MAX;
  for(int i=ind;i<s.size();i++)
  {
    if(s[i]=='W')
      w++;
    else
      b++;
    int temp=dfs(i+1,s,k-1);
    if(temp!=-1 && temp!=INT_MAX)
      mini=min(mini,temp+w*b);
  }
  dp[ind][k]=mini;
  return mini;
}
int Solution::arrange(string A, int B)
{
  if(B>A.size())
    return -1;
  memset(dp,-1,sizeof(dp));
  return dfs(0,A,B);
 
}
