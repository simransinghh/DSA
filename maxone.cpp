vector<int> Solution::maxone(vector<int> &A, int B) {
    int o = 0;
    int t = 1;
    int temp = B;
    int maxsize = 0;
    int start,end;
    vector<int> ans;
    if(A[0]==0 && temp>0) temp--;
    if(A[0]==0 && B == 0){
        o++;
        t++;
    }
    for(o;o<A.size();o++){
        if(A[o]==0 && temp>0 && o>=t) temp--;
        else if(A[o]==0 && temp==0 && o>=t){
            o++;
            continue;
        }
        if(o>=t) t = o+1;
        while(t<A.size()){
            if(temp>0 && A[t]==0){
                temp--;
                t++;
            }else if(A[t]==1) t++;
            else{
                break;
            }
        }
        int x = t-o;
        if(B==0 && A[o]==0){
            x = 0;
            temp--;
        }
        if(maxsize<x){
            start = o;
            end = t-1;
            maxsize = x;
        }
        while(A[o]==1 && o<A.size()){
            o++;
        }
        if(A[o]==0 && B!=0){
            temp++;
        }
    }
    for(int i=start;i<end+1;i++){
        ans.push_back(i);
    }
    return ans;
}

