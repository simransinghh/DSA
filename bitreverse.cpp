unsigned int Solution::reverse(unsigned int A) {
    unsigned int n = 0;
    for(int i=0;i<32;i++){
        n = n<<1;
        n = n|(A&1);
        A = A>>1;
        // cout<<n<<" "<<A;
        // cout<<" "<<n<<endl;    
        
    }
    return n;
}
