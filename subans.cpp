void subAns(int i,vector<vector<int>> &res,vector<int> &sub,vector<int> &A){
res.push_back(sub);
for(int indx=i;indx<A.size();indx++){
    if(indx==i||A[indx-1]!=A[indx]){
    sub.push_back(A[indx]);
    subAns(indx+1,res,sub,A);
    sub.pop_back();
    }
}
return;
}
vector<vector<int>> Solution::subsetsWithDup(vector<int> &A) {
sort(A.begin(),A.end());
vector<int>  sub;
vector<vector<int> > res;
subAns(0,res,sub,A);
return res;
}
