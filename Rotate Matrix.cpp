void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout 
    for(int i=0;i<A.size();i++)
    for(int j=i+1;j<A.size();j++)
    swap(A[i][j],A[j][i]);
    for(int i=0;i<A.size();i++)
    for(int j=0;j<A.size()/2;j++)
    swap(A[i][j],A[i][A.size()-1-j]);
}

