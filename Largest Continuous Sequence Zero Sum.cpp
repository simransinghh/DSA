vector<int> Solution::lszero(vector<int> &A) {
        vector<int> prefix(A.size());
        unordered_map<int,pair<int,int>> a;
        pair<int,int> maxx = make_pair(-1,-1);
        int difmax = 0;
        prefix[0] = A[0];
        a[A[0]] = make_pair(0,-1);
        if(A[0]==0){ 
                a[A[0]] = make_pair(0,0);
                difmax = 1;
                maxx = a[A[0]];
        }
        for(int i=1;i<A.size();i++){
                prefix[i] = A[i] + prefix[i-1];
                auto it = a.find(prefix[i]);
                if(prefix[i] == 0){
                        a[prefix[i]] = make_pair(0,i);
                        if(i+1>difmax){
                                difmax = i+1;
                                maxx = a[prefix[i]];
                        }
                }
                else if(it == a.end()){
                    a[prefix[i]] = make_pair(i,-1);
                    // cout<<i<<" "<<a[prefix[i]].first<<endl;
                }
                else{
                        pair<int,int> z = a[prefix[i]];
                        if(z.second == -1) z.first++;
                        z.second = i;
                        a[prefix[i]] = z;
                        // cout<<i<<" match "<<a[prefix[i]].first<<a[prefix[i]].second<<endl;
                        if(z.second - z.first + 1 > difmax){
                                difmax = z.second - z.first + 1;
                                maxx = a[prefix[i]];
                                // cout<<difmax<<" "<<maxx.first<<maxx.second<<endl;
                        }      
                }
        }
        vector<int> sub;
        if(difmax==0) return sub;
        // cout<<difmax<<" "<<maxx.first<<maxx.second<<endl;
        for(int i = maxx.first;i<=maxx.second;i++){
            sub.push_back(A[i]);
        }
        return sub;
}
