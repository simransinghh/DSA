bool dfshelper(int x,int y,int i,int j,vector<vector<int>> &matrix){
    if(i==x && j==y) return true;
    if(matrix[i][j] == -1) return false;
    matrix[i][j] = 1;
    bool ans;
    if(i>0){
        if(matrix[i-1][j] == 0) ans = dfshelper(x,y,i-1,j,matrix);
        if(j>0 && matrix[i-1][j-1] == 0) ans = ans || dfshelper(x,y,i-1,j-1,matrix);
        if(j <= y-1 && matrix[i-1][j+1]==0) ans = ans || dfshelper(x,y,i-1,j+1,matrix);
    }
    if(i<=x-1){
        if(matrix[i+1][j] == 0) ans = ans || dfshelper(x,y,i+1,j,matrix);
        if(j>0 && matrix[i+1][j-1] == 0) ans = ans || dfshelper(x,y,i+1,j-1,matrix);
        if(j <= y-1 && matrix[i+1][j+1]==0) ans = ans || dfshelper(x,y,i+1,j+1,matrix);
    }
    if(j>0 && matrix[i][j-1] == 0) ans = ans || dfshelper(x,y,i,j-1,matrix);
    if(j <= y-1 && matrix[i][j+1]==0) ans = ans || dfshelper(x,y,i,j+1,matrix);
    return ans;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

    vector<vector<int>> matrix(A+1,vector<int>(B+1,0));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int p = 0; p < C; p++) {
                if(E[p]==A && F[p]==B){
                    return "NO";
                }
                if(E[p]==0 && F[p]==0){
                    return "NO";
                }
                if(pow((E[p] - i), 2) + pow((F[p] - j), 2) <= pow(D,2))  {
                    matrix[i][j] = -1;
                }
            }
        }
    }    
    if(dfshelper(A,B,0,0,matrix)) return "YES";
    return "NO";
}
