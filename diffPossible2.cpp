int Solution::diffPossible(const vector<int> &A, int B) {
        unordered_map<int,int> bla;
        for(int i = 0;i<A.size();i++){
                int x = A[i]+B;
                int y = A[i] - B;
                auto it = bla.find(x);
                auto yt = bla.find(y);
                if((it != bla.end() && it->second != i) || (yt != bla.end() && yt->second != i)){
                    // cout<<A[i]<<" "<<it->first<<endl;
                    return 1;
                }
                bla[A[i]] = i;
        }
        return 0;

}
