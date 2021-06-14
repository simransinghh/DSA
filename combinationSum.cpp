void dfs(vector<int >& nums, vector<int >& ans, vector<vector<int >>& res, int start,int target) {

     if(target<0)    
     {
         return;
     }
     else if(target==0)     
                             
     {
          res.push_back(ans);
         return ;
     }
    for (int i = start; i < nums.size(); i++) {
      
        ans.push_back(nums[i]);
        dfs(nums, ans, res, i ,target-nums[i]);   
        ans.pop_back();
    }
}
vector<vector<int >> Solution::combinationSum(vector<int > &nums, int target) {
    vector<int > ans;
    vector<vector<int >> res;
    sort(nums.begin(), nums.end());
    dfs(nums, ans, res, 0,target);
    set<vector<int >>st(res.begin(),res.end());
    res.clear();
    for(auto it:st)
    {
        res.push_back(it);
    }
    return res;
}
