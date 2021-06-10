unsigned int fact(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
  
string getPer(int A, int B , int idx, int sum , vector<int> &s) {
    string ans;
    if(idx == A) return ans;
    int x = fact(A-idx-1);
    int cont = A;
    int q = 0;
    while(sum>=B && cont > 0){
         if(s[cont] == 1){
                 cont--;
                 continue;
         }
        sum -= x;
        cont--;
        q = 1;
    }
    cont++;
    if(q == 0){
        cont = 1;
        while(sum < B && cont<=A){
            if(s[cont] == 1){
                 cont++;
                 continue;
            } sum += x;
            cont++;
        }
        cont--;
    }
    // if(sum == B){
    //         char x = cont + '0';
    //         ans += x;
    //         s[cont] = 1;
    //         for(int j=1;j<=A;j++){
    //             if(s[j] == 1) continue;
    //             char z = j + '0';
    //             ans += z;
    //         }
    //         return ans;
    // }
    // else{
            s[cont] = 1;
            char z = cont + '0';
            ans = z + getPer(A,B,idx+1,sum,s);
    // }
    return ans;
}

string Solution::getPermutation(int A, int B) {
    if(B==1){
        string ans;
        for(int j=1;j<=A;j++){
            char z = j + '0';
            ans += z;
            }
            return ans;
    }
    vector<int> s(A+1,0);
    return getPer(A,B,0,0,s);
    
}
