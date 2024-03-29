int Solution::isValidSudoku(const vector<string> &A) {
    unordered_map<int, unordered_set<char>> row, col, sec;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].length(); j++){
            if(A[i][j] != '.'){
                if(row[i].find(A[i][j]) != row[i].end() || col[j].find(A[i][j]) != col[j].end())
                    return 0;
                int s = (j/3)+10*(i/3);
                if(sec[s].find(A[i][j]) != sec[s].end())
                    return 0;
                row[i].insert(A[i][j]);
                col[j].insert(A[i][j]);
                sec[s].insert(A[i][j]);
            }
        }
    }
    row.clear(); col.clear(); sec.clear();
    return 1;
}
