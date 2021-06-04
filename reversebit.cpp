unsigned int reverse(unsigned int A) {
    unsigned int n = 0;
    for(int i=0;i<31;i++){
        n = n|(A&1);
        A = A>>1;
        n = n<<1;
    }
    n = n|(A&1);
    A = A>>1;
    return n;
}
