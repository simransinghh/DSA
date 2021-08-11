vector<int> Solution::solve(vector<int> &a, int B) {
int n=a.size();
unordered_map<int,int>m;
for(int i=0;i<n;i++){
    m[a[i]]=i;
}
for(int i=0;i<n;i++){
    if(B>0){
        if(a[i]!=n-i){
            B--;
            m[a[i]]=m[n-i];
            a[m[n-i]]=a[i];
            m[n-i]=i;
            a[i]=n-i;
        }
    }else{
        break;
    }
}
return a;
}
