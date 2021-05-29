int Solution::power(string A) {
    if(A == "1") return 0;
    int len  = A.length();
    int no = 0;
    while(A.length() != 1 || A[A.length()-1] != '1'){
        if(A[len-1] % 2 == 1) return 0;
        for (int i = 0; i < len; i++) {
            no = no*10 + A[i]-'0';
            if(no < 2){
                if(i != 0){
                    A[i] = '0';
                    continue;
                }
                A = A.substr(1);
                len--;
                i--;
                continue;
            }
            A[i] = (int)no/2 + '0';
            no = no%2;
        }
        len = A.length();
        if(no>0) return 0;
    }
    return 1;
}
