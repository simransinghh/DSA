#include <bits/stdc++.h>
using namespace std;

string Solution::solve(string A) {
    string sol;
    queue<char> q;
    int arr[26] = {0}; 
    for(int i = 0;i<A.length();i++){
        int x = A[i] - 97;
        if(arr[x] == 0){
            q.push(A[i]);
        }
        arr[x]++;
        if(q.empty()){
            char c = '#';
            sol.push_back(c);
            continue;
        }
        int y = q.front() - 97;
        if(arr[y]==1){
            sol.push_back(q.front());
        }else{
            q.pop();
            i--;
        }
    }
    while(sol.length()<A.length()){
        if(!q.empty()){
            sol.push_back(q.front());
        }else{
            sol.push_back('#');
        }
    }
    return sol;
// "cxbctvqxq"
}
vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
        
    deque <int> dq;
    vector <int> ans;
        
    for (int i = 0; i < k; i++){
            
        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
            
        dq.push_back(i);
    }
        
    ans.push_back(arr[dq.front()]);
        
    for (int i = k; i < arr.size(); i++){
        int last_pos = i-k+1;
        while (!dq.empty() && dq.front() < last_pos){
            dq.pop_front();
        }
            
        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
            
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
    }
        
    return ans;
}


int main() {
    // char a = 'a';
    // int A = a ;
    // cout<<A;
    cout<<solve("cxbctvqxq");
    // vector<int> C =
    // vector<int> ans
    // cout<<ans[0]<<ans[1];
}
