int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int prefix = 0;          
    unordered_map<int, int> map; 

    for (int ele : A)
    {
        prefix = prefix ^ ele;
        if (prefix == B)
            count++;
        count += map[prefix ^ B];
        map[prefix]++;
    }

    return count;
}

