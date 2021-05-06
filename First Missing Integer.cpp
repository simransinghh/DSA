int Solution::firstMissingPositive(vector<int> &A) {

    for(int i =0;i<A.size();i++){
        if(A[i] <= 0){
            A[i]=0;
        }
        if(A[i]==i+1){
            continue;
        }
        if(A[i]>0 && A[i]<=A.size()){
            if(A[A[i]-1] == A[i]){
                A[i] = 0;
                continue;
            }
            swap(A[i],A[A[i]-1]);
            i--;
            continue;
        }
    }

    for(int i=0;i<A.size();i++){
        if(A[i] != i+1){
            return i + 1;
        }
    }
    return A.size()+1;


}
