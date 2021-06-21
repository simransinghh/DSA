int Solution::solve(string A) {
    map<char,int>mp;
    for(auto ch : A)
        mp[ch]++;

    int o=0;
    for(auto it : mp)
    {
        if(it.second%2==1)
        o++;
    }

    if(o>1)
        return 0;
    else return 1;
}
