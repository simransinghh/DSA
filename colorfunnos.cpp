int Solution::colorful(int A) {
    unordered_map<int, int> map;
    int acc, a;
    
    while(A){
        int acc = 1;
        int a = A;
        while(a){
            acc *= a % 10;
            a /= 10;
            if(map[acc] == 1) return 0;
            map[acc] = 1;
        }
        A /= 10;
    }
    return 1;
}
