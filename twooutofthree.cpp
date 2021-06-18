vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

        vector<int> ans;
        unordered_map<int,int> map;
        for(int i = 0;i<A.size();i++){
                map[A[i]] = 1;
        }
        int i = 0,j = 0;
        int bsize = B.size();
        int csize = C.size();
        while(i<bsize || j<csize){
                if(i<bsize && j<csize){
                              auto bt = map.find(B[i]);
                              if(bt != map.end()){
                                      if(map[B[i]]!=2){
                                              if(map[B[i]] != 4) ans.push_back(B[i]);
                                              map[B[i]] = 4;
                                      } 
                              }else{
                                      map[B[i]] = 2;
                              }
                              i++;
                              auto it = map.find(C[j]);
                              if(it != map.end()){
                                      if(map[C[j]]!=3){
                                            if(map[C[j]] != 4) ans.push_back(C[j]);
                                            map[C[j]] = 4;
                                      } 
                              }else{
                                      map[C[j]] = 3;
                              }
                              j++;
              }else if(i<bsize){
                    auto it = map.find(B[i]);
                    if(it != map.end()){
                        if(map[B[i]]!=2){
                                              if(map[B[i]] != 4) ans.push_back(B[i]);
                                              map[B[i]] = 4;
                        }  
                    }else{
                                map[B[i]] = 2;
                    }
                    i++;  
              }else{
                    auto it = map.find(C[j]);
                    if(it != map.end()){
                         if(map[C[j]]!=3){
                                            if(map[C[j]] != 4) ans.push_back(C[j]);
                                            map[C[j]] = 4;
                         }  
                    }else{
                        map[C[j]] = 3;
                    }
                    j++;   
              }  
        }
        sort(ans.begin(),ans.end());
        return ans;
}
