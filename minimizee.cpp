int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    bool a = false,b = false,c = false;
    int n = A.size() , m = B.size() , l = C.size();
    cout<<n<<" "<<m<<" "<<l<<endl;
    int i=0,j=0,k=0;
    int ans = INT_MAX;
    while(!a || !b || !c){
        int tempmax = INT_MIN;
        int tempmin = INT_MAX;
        cout<<i<<"->"<<A[i]<<" "<<j<<"->"<<B[j]<<" "<<k<<"->"<<C[k]<<endl;
        for(int q=0;q<3;q++){
            if(q==0 && !a){
                tempmax = A[i];
                tempmin = A[i];
                if(i==n-1) a = true;
            }
            if(q==1 && !b){
                tempmax = max(tempmax,B[j]);
                tempmin = min(tempmin,B[j]);
                if(j==m-1) b = true;
            }
            if(q==2 && !c){
                tempmax = max(tempmax,C[k]);
                tempmin = min(tempmin,C[k]);
                if(k==l-1) c = true;
            }
        }
        ans = min(ans,tempmax-tempmin);
        cout<<ans<<" "<<tempmax<<" "<<tempmin<<endl;
        if(A[i]==tempmin && i!=n-1) i++;
        if(B[j]==tempmin && j!=m-1) j++;
        if(C[k]==tempmin && k!=l-1) k++;
        cout<<"----------------------------------"<<endl;
    }
    return ans;
}
