int Solution::solve(vector<int> &A) {
    int n = A.size();

    vector<int> right(n);

    right[n - 1] = A[n - 1];

    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],A[i]);
    }

    set<int> s;
    s.insert(A[0]);
    int ans = 0;

    for(int i = 1;i<n - 1;i++){
        if(A[i] >= right[i + 1])
            continue;

        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);

        if(it == s.begin())
            continue;

        it--;
        ans = max(ans,*it + A[i] + right[i+1]);

    }

    return ans;
}
