int Solution::maxArea(vector<int> &A) {
    int n=A.size(),i=0,j=n-1,ans=0,h;
    while(i<j){
        h=min(A[i],A[j]);
        ans=max(ans,h*(j-i));
        A[i]<A[j]?i++:j--;
    }
    return ans;
}
