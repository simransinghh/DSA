vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int N = A.size();
    vector<vector<int> > arr(2*N - 1);
     for (int col = 0; col < N; col++) {
 
        int startcol = col, startrow = 0;
        while (startcol >= 0 && startrow < N) {
            arr[col].push_back(A[startrow][startcol]);
            startcol--;
            startrow++;
        }
    }
    for (int row = 1; row < N; row++) {
        int startrow = row, startcol = N - 1;
 
        while (startrow < N && startcol >= 0) {
            arr[N -1 + row].push_back(A[startrow][startcol]);
 
            startcol--;
 
            startrow++;
        }
    }
    return arr;
}
