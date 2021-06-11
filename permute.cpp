void perm(vector<vector> &ans, int s, vector A){

if(s==A.size()-1){
    ans.push_back(A);
    return;
}
for(int i = s;i<A.size();i++){
        swap(A[i],A[s]);
        perm(ans, s+1, A);
        swap(A[i],A[s]);
}
}

vector<vector > Solution::permute(vector &A) {
vector<vector> ans;
perm(ans, 0 , A);
return ans;

}

