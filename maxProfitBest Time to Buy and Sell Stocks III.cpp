int Solution::maxProfit(const vector<int> &A) {
if(A.empty()) return 0;
int one_t=0,two_t=0;
int mp1=INT_MAX, mp2=INT_MAX;
for(int i : A){
    mp1 = min(mp1,i);
    one_t = max(one_t,i-mp1);
    mp2 = min(mp2,i-one_t);
    two_t = max(two_t,i-mp2);
}
return two_t;
}
