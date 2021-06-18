int Solution::solve(vector<int> &A, int B) {
        unordered_map<int,int> xorr;
        int count =0;
        for(int i=0;i<A.size();i++){
                int x = B^A[i];
                auto it = xorr.find(x);
                auto me = xorr.find(A[i]);
                if(me != xorr.end()) continue;
                if(it != xorr.end()){
                        count++;
                }
                xorr[A[i]] = i;
        }
        return count;
}
