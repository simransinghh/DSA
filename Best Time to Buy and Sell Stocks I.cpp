int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0) return 0;
    int maxprofit = 0;
    int minno = A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]<minno) minno = A[i];
        else if(A[i]>minno){
            maxprofit = max(maxprofit,A[i]-minno);
        }
    }
    return maxprofit;
}
