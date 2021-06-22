#define MAXN 105
int dp[MAXN]; 
int nck[MAXN][MAXN]; 
int log22[MAXN]; 
long long int MOD = 1000000007;
int choose(int n, int k)
{
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
  
    if (nck[n][k] != -1)
        return nck[n][k];
  
    int answer = choose(n - 1, k - 1) + choose(n - 1, k);
    answer%=MOD;
    nck[n][k] = answer;
    return answer;
}
int getLeft(int n)
{
    if (n == 1)
        return 0;
    int h = log22[n];
    int numh = (1 << h); 
    int last = n - ((1 << h) - 1);
    if (last >= (numh / 2))
        return (1 << h) - 1; 
    else
        return (1 << h) - 1 - ((numh / 2) - last);
}
int numberOfHeaps(int n)
{
    if (n <= 1)
        return 1;
  
    if (dp[n] != -1)
        return dp[n];
  
    int left = getLeft(n);
    long long int ans = (choose(n - 1, left) * numberOfHeaps(left)) * 
                             (numberOfHeaps(n - 1 - left));
    ans%=MOD;
    dp[n] = ans;
    return ans;
}
int Solution::solve(int n)
{
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
  
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            nck[i][j] = -1;
  
    int currLog2 = -1;
    int currPower2 = 1;
    for (int i = 1; i <= n; i++) {
        if (currPower2 == i) {
            currLog2++;
            currPower2 *= 2;
        }
        log22[i] = currLog2;
    }
  
    return (int)numberOfHeaps(n);
}
  
