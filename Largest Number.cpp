bool compare(int x,int y) {
    string st1 = to_string(x);
    string st2 = to_string(y);
    return (st1+st2)>(st2+st1);
}
string Solution::largestNumber(const vector<int> &A) {
    vector B = A;
    sort(B.begin(),B.end(),compare);
    string ans;
    for(int i=0;i<B.size();i++){
        ans+=to_string(B[i]);
    }
    return ans;
}
