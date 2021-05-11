int Solution::isPalindrome(string A) {
    int ans = 0;
    int j = A.length()-1;
    int i =0;
    while(i<j){
        if((A[i]>90 || A[i]<65) && (A[i]>122 || A[i]<97) && (A[i]>58 || A[i]<48)){
            i++;
            continue;
        }
        if((A[j]>90 || A[j]<65) && (A[j]>122 || A[j]<97) && (A[i]>58 || A[i]<48)){
            j--;
            continue;
        }
        if(A[j]==A[i] || A[j]==A[i]+32 || A[i]==A[j]+32){
            j--;
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
