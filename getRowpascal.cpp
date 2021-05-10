vector<int> Solution::getRow(int A) {
    
    vector<int> ans; 
    int prev = 1;
    ans.push_back(prev);
 
    for (int i = 1; i <= A; i++) {
        int curr = (prev * (A- i + 1)) / i;
        ans.push_back(curr);
        prev = curr;
    }
    return ans;
}
