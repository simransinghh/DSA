vector<int> subsetsum(vector<int> &weight, int W )
{
    bool t[weight.size()+1][W+1];

    for(int i=0;i<weight.size()+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 && j==0)    t[i][j] = true;
            else if(i==0)   t[i][j] = false;
            else if(j==0)   t[i][j] = true;
            else
            {
                if(weight[i-1]>W)   t[i][j] = t[i-1][j];
                else t[i][j] = t[i-1][j] || t[i-1][j-weight[i-1]];
            }
        }
    }
    vector<int> ans;
    for(int j=0;j<W+1;j++)
    {
        if(t[weight.size()][j]==true)   ans.push_back(j);
    }

    return ans;
}


int Solution::solve(vector<int> &A)
{
    int S = 0;
    int n = A.size();
    if(n==1)    return A[0];
    for(int i=0;i<n;i++)    S+=A[i];

    vector<int> allowed = subsetsum(A,S);
    
    int ans = INT_MAX;
    for(int i=0;i<allowed.size();i++)
    {
        ans = min(ans,abs(S-(2*allowed[i])));
    }

    return ans;

}
