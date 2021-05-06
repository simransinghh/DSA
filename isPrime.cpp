bool isPrime(int n){ //Sieve of Eratosthenes
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}


vector<int> Solution::primesum(int A) {
    if(A % 2 == 0 && A > 2){
        vector<int> res;
        for(int i = 2; i<=A/2; i++){
            if(isPrime(i) && isPrime(A-i)){
                res.push_back(i);
                res.push_back(A-i);
                break;
            }
        }
        return res;
    }
    
}
