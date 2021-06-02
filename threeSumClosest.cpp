int Solution::threeSumClosest(vector<int> &A, int target) {
    int n=A.size();
    sort(A.begin(),A.end());
    long  bestSum=INT_MAX,sum=0;
    for(int i=0;i<n-2;i++){
        int start=i+1,end=n-1;
        while(start<end){
            sum=long(A[i])+A[start]+A[end];
            if(abs(target-sum)<abs(target-bestSum))
                bestSum=sum;
            else if(sum>target)
                end--;
            else
                start++;
        }
    }
    return bestSum;
}
