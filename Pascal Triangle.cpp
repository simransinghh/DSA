vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> arr(A);
    for (int line = 0; line < A; line++){
        for (int i = 0; i <= line; i++){
        if (line == i || i == 0)
            arr[line].push_back(1);

        else
            arr[line].push_back(arr[line - 1][i - 1] + arr[line - 1][i]);
        }
    }
    return arr;
}
