vector<int> Solution::solve(vector<int> &A) {
        unordered_map<int,int> bla;
        for(int i = 0;i<A.size();i++){
                int y = A[i];
                auto it = bla.find(y);
                if(it == bla.end()){
                        bla[A[i]] = i;
                }else{
                        int idx = bla[A[i]];
                        bla[A[i]] = i;
                        A[idx]++;
                        int x = A[idx];
                        auto xt = bla.find(x);
                        if(xt != bla.end()){
                                if(xt->second > idx) bla[x] = idx;
                        }else{
                                bla[x] = idx;
                        }
                }
        }

        return A;
}
