#include <bits/stdc++.h>
using namespace std;

int Solution::maxSpecialProduct(vector<int> &A) {
    long long int mod = 1000000007;
    int n = A.size();
    vector<long long> pro(n,-1);
    stack<int> s;
    int max = 0;
    for(int i=0;i<n;i++){
        if(s.empty()){
            pro[i] = 0;
            s.push(i);
        }
        //check eqaulity conditions and empty
        else if(A[i]>=A[s.top()]){
            while(!s.empty() && A[s.top()]<A[i]){
                int right =i;
                if(pro[s.top()]==-1) pro[s.top()] = right;
                else pro[s.top()] *= right;
                s.pop();
            }
            if(s.empty()) pro[i] = 0;
            else if(A[s.top()] == A[i]){
                int left = pro[s.top()];
                if(pro[i]==-1) pro[i] = left;
                else pro[i] *= left;
            }
            else {
                int left = s.top();
                if(pro[i]==-1) pro[i] = left;
                else pro[i] *= left;
            } 
            s.push(i);
        }
        else{

            int left = s.top();
            if(pro[i]==-1) pro[i] = left;
            else pro[i] *= left;
            s.push(i);

        }
            
    }
    while(!s.empty()){
        pro[s.top()] = 0;
        s.pop();
    }
    int index = max_element(pro.begin(),pro.end()) - pro.begin();
    return pro[index]% 1000000007;
}


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> pro(n,-2);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            pro[i] = -1;
            s.push(i);
        }
        //check eqaulity conditions and empty
        else if(A[i]<=A[s.top()]){
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()) pro[i] = -1;
            else {
                pro[i] = A[s.top()];
            } 
            s.push(i);
        }
        else{
            pro[i] = A[s.top()];
            s.push(i);
        }     
    }
    while(!s.empty()){
        if(pro[s.top()] == -2) pro[s.top()] = -1;
        s.pop();
    }
   
    return pro;


}
largestRectangleArea



int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
