#include <bits/stdc++.h>
using namespace std;


int Solution::solve(vector<int> &A, int B) {
        int sum = 0;
        priority_queue<int> pq;
        for(int i: A) pq.push(A[i]);
        while(B--){
                int a = pq.top();
                pq.pop();
                sum += a;
                if(a>1) pq.push(a-1)
        }
        return sum;
}



vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    priority_queue<int> pq;
    for(int i: A) pq.push(i);
    while(B--){
        int ans = pq.top(); pq.pop();
        res.push_back(ans);
    }
    return res;
}
vector<int> Solution::solve(vector<int> &A, int B) {
        vector<int> ans;
        A.sort(A.begin(),A.end(),greater<int>());
        for(int i=0;i<B;i++){
                ans.push_back(A[i]);
        }
        return ans;
}


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
        int n=A.size();
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        priority_queue<int, vector<int>,greater<int>> pq;
        vector<int> ans;
        for(int i=0;i<A.size();i++)
                for(int j=0;j<B.size();j++)
                {
                        int sum=A[i]+B[j];
                        if(i==0) pq.push(sum);
                        else if(sum>pq.top()){
                                pq.pop();
                                pq.push(sum);
                        }
                        else break;
                }
        while(n--){
                ans.push_back(pq.top());
                pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
        int maxsum = INT_MIN;
        int n = A.size();
        vector<int> a;
        priority_queue<int> g;
        for(int i = 0;i<n;i++){
                for(int j=0;j<n;j++){
                        int x = A[i] + B[j];
                        g.push(x);
                }
        }
        int i = 0;
        while(i<n && !g.empty())
                a.push_back(g.top());
                g.pop();
                i++;
        }
        return a;
}


#define MAXN 105
int dp[MAXN]; 
int nck[MAXN][MAXN]; 
int log22[MAXN]; 
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
    int ans = (choose(n - 1, left) * numberOfHeaps(left)) * 
                             (numberOfHeaps(n - 1 - left));
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
  
    return numberOfHeaps(n);
}
  

//  L + R = (n-1) 

//  (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 

// Find the height of the heap h = log2(n)

// Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h

// Find the number of elements that are actually present in last level(hth level) p = n - (2h - 1)

//  L = 2h - 1 if p >= m/2
//                     = 2h - 1 - (m/2 - p) if p<(m/2) 

int Solution::solve(int n) {
        int h = log(n);
        int maxele = pow(2,h);
        int p = n - maxele - 1;
        int l,r;
        if(p >= m/2) l = maxele-1;
        else l = maxele/2 - 1 + p;
        r = n - 1 - l;
        int ncl = fact(n-1) / (fact(l) * fact(n - 1 - l));
        return ncl*solve(l)*solve(r);
}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
