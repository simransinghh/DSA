vector<int> Solution::equal(vector<int> &A) {
        unordered_map<int,pair<int,int>> sum;
        vector<vector<int>> v;
        for(int i = 0;i<A.size()-1;i++){ //C
                for(int j = i+1;j<A.size();j++){ //D
                        int tempsum = A[i] + A[j];
                        // cout<<endl<<i<<"+"<<j<<" "<<tempsum;
                        auto it = sum.find(tempsum);
                        if(it != sum.end()){
                                pair<int,int> milgya = it->second; // A B
                                // cout<<endl<<milgya.first<<" "<<milgya.second;
                                if(milgya.second != j && milgya.second != i && milgya.first != i && milgya.first != j){
                                        vector<int> ans;
                                        ans.push_back(milgya.first);
                                        ans.push_back(milgya.second);
                                        ans.push_back(i);
                                        ans.push_back(j);
                                        v.push_back(ans);
                                }
                                // else{
                                //         milgya = make_pair(i,j);
                                //         // cout<<endl<<milgya.first<<" "<<milgya.second;
                                //         sum[tempsum]=milgya;
                                // } 
                        }else{
                            pair<int,int> x = make_pair(i,j);
                            // cout<<endl<<"notfound"<<x.first<<" "<<x.second;
                            sum[tempsum]=x;
                        }
                }

        }
        sort(v.begin(),v.end());
        return v[0];
}
