int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    if(n==1) return A[0][0];
    vector<int> vec = A[n-1];
    int i = n-2;
    while(i >=0)
    {
        for(int j=0;j<=i;j++)
            vec[j] = min(vec[j],vec[j+1])+A[i][j];
        vec.erase(vec.end()-1);
        i--;
    }
    return vec[0];
}
