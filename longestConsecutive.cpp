int Solution::longestConsecutive(const vector<int> &a) {
        int ans = 1;
        int temp = 1;
        vector<int> A = a;
        sort(A.begin(),A.end());
        unordered_map<int,int> pq;
        for(int i=0;i<A.size();i++)
        {
            if(pq.find(A[i]) != pq.end()) continue;
                if(pq.find(A[i]-1) != pq.end()){
                        pq[A[i]] = pq[A[i-1]]+1;
                }
                else  pq[A[i]]++;
                ans = max(ans,pq[A[i]]);
                // cout<<i<<ans<<endl;
        }
        // for(int i=0;i<A.size();i++)
        // {
        //         while()
        // }
        return ans;
}
