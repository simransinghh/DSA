void Solution::setZeroes(vector<vector<int> > &A) {
    set<int> r,c;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
        if(A[i][j]==0) r.insert(i),c.insert(j);
        
    for(auto i=r.begin();i!=r.end();i++)
        for(int j=0;j<A[0].size();j++) A[*i][j]=0;
    
    for(auto i=c.begin();i!=c.end();i++)
        for(int j=0;j<A.size();j++) A[j][*i]=0;
    
}
