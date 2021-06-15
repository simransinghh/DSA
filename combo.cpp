void comb(int A,int B,vector<vector<int>>&ans,vector<int>&res,int l)
{
    if(res.size()==B)
    {   
        ans.push_back(res);
        return;
    }
    for(int i=l;i<=A;i++)
    {
        res.push_back(i);
        comb(A,B,ans,res,i+1);
        res.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> arr;
    vector<int> res;
    vector<vector<int>> ans;
    comb(A,B,ans,res,1);
    return ans;
}
