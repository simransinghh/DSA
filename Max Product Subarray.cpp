int Solution::maxProduct(const vector<int> &A) {
    // max_ending_here gives a max val when big +ve subsequence mutiplied with
    // a +ve number. min_ending_here keeps track of largest(in magnitude) -ve subseq
    // and when a -ve num multiplied, gives a big +ve ans
    
    int N = A.size();
    if(N == 0) return 0;
    else if(N == 1) return A[0];
    else {
        int max_ending_here = A[0], min_ending_here = A[0];
        int max_overall = A[0];
        
        for(int i = 1; i<N; i++){
            int temp = max_ending_here;
            max_ending_here = max({A[i], max_ending_here*A[i], min_ending_here*A[i]});
            min_ending_here = min({A[i], temp*A[i], min_ending_here*A[i]});
            max_overall = max(max_overall, max_ending_here);
        }
        return max_overall;
    }
}
