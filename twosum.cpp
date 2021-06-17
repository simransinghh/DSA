vector<int> Solution::twoSum(const vector<int> &A, int B) {
            
                unordered_map<int,int> map;
                
                for (int i = 0; i < A.size(); i++){
                    
                    if(map.find(B - A[i]) != map.end()){
                        return {map[B - A[i]] + 1, i + 1};
                    }
                    else{
                        map.insert(make_pair(A[i], i));
                    }
                }
                return {};
}
