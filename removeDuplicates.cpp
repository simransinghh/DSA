int Solution::removeDuplicates(vector<int> &A) {
    int i = 0, j = 0, n = A.size();
    while (i < n && j < n)
    {
        while (j < n && A[j] == A[i]) j++;    
        A[++i] = A[j]; 
    }
    return i;
}
