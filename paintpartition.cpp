#define MOD 10000003
int maxtime(int A, vector<int> &C, int maxx){
    int s = C.size();
    int sum = 0;
    int newmax = -1;
    for(int i=0;i<s;i++){
        if(A==0) return -1;
        sum += C[i];
        if(sum>maxx){
            i--;
            sum = 0;
            A--;
        }else{
            if(newmax<sum) newmax = sum;
        }
    }
    return newmax;

}
int Solution::paint(int A, int B, vector<int> &C) {
    int s = C.size();
    long long int sum = 0;
    int maxx = 0;
    for(int i=0;i<s;i++){
        sum += C[i];
        if(C[i]>maxx) maxx = C[i];
    }
    if(A>=s) return ((B % MOD) * (maxx % MOD)) % MOD;
    if(A==1) return ((B % MOD) * (sum % MOD)) % MOD;
    int st = maxx;
    long long int end = sum;
    long long int ans = sum+1;
    while(st<=end){
        int mid = (st+end)/2;
        int tempanns = maxtime(A,C,mid);
        if(tempanns == -1){
            st = mid + 1;
        }else{
            if(ans>tempanns) ans = tempanns;
            end = tempanns - 1;
        }
    }
    if(ans == sum + 1) return -1;
    return ((B % MOD) * (ans % MOD)) % MOD;
}
