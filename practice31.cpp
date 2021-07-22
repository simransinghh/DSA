#include <bits/stdc++.h>
using namespace std;
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle

bool dfshelper(int x,int y,int i,int j,int** matrix){
    if(i==x && j==y) return true;
    if(matrix[i][j] == -1) return false;
    matrix[i][j] = 1;
    bool ans;
    if(i>0){
        if(matrix[i-1][j] == 0) ans = dfshelper(x,y,i-1,j,matrix);
        if(j>0 && matrix[i-1][j-1] == 0) ans = ans || dfshelper(x,y,i-1,j-1,matrix);
        if(j < y-1 && matrix[i-1][j+1]==0) ans = ans || dfshelper(x,y,i-1,j+1,matrix);
    }
    if(i<x-1){
        if(matrix[i+1][j] == 0) ans = ans || dfshelper(x,y,i+1,j,matrix);
        if(j>0 && matrix[i+1][j-1] == 0) ans = ans || dfshelper(x,y,i+1,j-1,matrix);
        if(j < y-1 && matrix[i+1][j+1]==0) ans = ans || dfshelper(x,y,i+1,j+1,matrix);
    }
    if(j>0 && matrix[i][j-1] == 0) ans = ans || dfshelper(x,y,i,j-1,matrix);
    if(j < y-1 && matrix[i][j+1]==0) ans = ans || dfshelper(x,y,i,j+1,matrix);
    return ans;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

    int matrix[A][B] = {0};
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int p = 0; p < C; p++) {
                if(E[p]==A && F[p]==B){
                    return "NO";
                }
                if(E[p]==0 && F[p]==0){
                    return "NO";
                }
                if((pow((E[p] - i), 2) + pow((F[p] - j), 2)))<= pow(D,2){
                    matrix[i][j] = -1;
                }
            }
        }
    }    
    if(dfshelper(A,B,0,0,matrix)) return "YES";
    return "NO";
}










string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int matrix[A+1][B+1] = {0};
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int p = 0; p < C; p++) {
                if(E[p]==A && F[p]==B){
                    return "NO";
                }
                if(E[p]==0 && F[p]==0){
                    return "NO";
                }
                if(sqrt((pow((E[p] - 1 - i), 2) + pow((F[p] - 1 - j), 2)))<= D){
                    matrix[i][j] = -1;
                }
            }
        }
    }
    // if (matrix[0][0] == -1)
    //     return "NO";
    
    queue<pair<int,int>> q;
    int x = 0,y = 0;
    pair<int,int> coord(x,y);
    q.push(coord);
    
    while(!q.empty()){
        coord = q.front();
        q.pop();
        int elex = coord.first;
        int eley = coord.second;
 
        if ((elex > 0) && (eley > 0)
            && (matrix[elex - 1][eley - 1] == 0)) {
            matrix[elex - 1][eley - 1] = 1;
            pair<int,int> v(elex - 1, eley - 1);
            q.push(v);
        }
 
        // check top cell
        if ((elex > 0) && (matrix[elex - 1][eley] == 0)) {
            matrix[elex - 1][eley] = 1;
            pair<int,int> v(elex - 1, eley);
            q.push(v);
        }
 
        // check top-right cell
        if ((elex > 0) && (eley < B - 1)
            && (matrix[elex - 1][eley + 1] == 0)) {
            matrix[elex - 1][eley + 1] = 1;
            pair<int,int> v(elex - 1, eley + 1);
            q.push(v);
        }
 
        // check left cell
        if ((eley > 0) && (matrix[elex][eley - 1] == 0)) {
            matrix[elex][eley - 1] = 1;
            pair<int,int> v(elex, eley - 1);
            q.push(v);
        }
 
        // check right cell
        if ((eley < B - 1) && (matrix[elex][eley + 1] == 0)) {
            matrix[elex][eley + 1] = 1;
            pair<int,int> v(elex, eley + 1);
            q.push(v);
        }
 
        // check bottom-left cell
        if ((elex < A - 1) && (eley > 0)
            && (matrix[elex + 1][eley - 1] == 0)) {
            matrix[elex + 1][eley - 1] = 1;
            pair<int,int> v(elex + 1, eley - 1);
            q.push(v);
        }
 
        // check bottom cell
        if ((elex < A - 1) && (matrix[elex + 1][eley] == 0)) {
            matrix[elex + 1][eley] = 1;
            pair<int,int> v(elex + 1, eley);
            q.push(v);
        }
 
        // check bottom-right cell
        if ((elex < A - 1) && (eley < B - 1)
            && (matrix[elex + 1][eley + 1] == 0)) {
            matrix[elex + 1][eley + 1] = 1;
            pair<int,int> v(elex + 1, eley + 1);
            q.push(v);
        }
    }
    if(matrix[A-1][B-1] == 1) return "YES";
    else return "NO";

}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
