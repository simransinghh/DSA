bool combo(int A,int B,int idx, vector<vector<int>>& ans){
        vector<vector<int>> x;
        if(B==0){
                vector<int> q;
                x.push_back(q);
                return true;
        }
        if(B>0 && idx>A){
                return false;
        }
        bool c = false;
        for(int i=idx;i<=A;i++){
            bool f = combo(A,B-1,i+1,x);
            if(f){
                    c = true;
                    if(x.empty()){
                        vector<int> q;
                        q.push_back(i);
                        ans.push_back(q);   
                    }
                    else{
                            for(int j=0;j<x.size();j++){
                                x[j].insert(x[j].begin(),i);
                                ans.push_back(x[j]);
                            }
                    }     
                
            }
            x.clear();
        }
        return c;
}
vector<vector<int>> Solution::combine(int A, int B) {
        vector<vector<int>> a;
        bool c = combo(A,B,1,a);
        return a;
}
