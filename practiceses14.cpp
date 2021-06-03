#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
   auto dxa = A.begin();
   auto dxb = B.begin();
   while(dxa != A.end() || dxb != B.end()){
       if(*dxa>*dxb){
           A.insert(dxa,*dxb);
           dxa = dxa+1;
           dxb = dxb+1;
       }
       else{
           dxa = dxa + 1;
       }
       if(dxb == B.end()) return;
   }
   while(dxb != B.end()){
       A.push_back(*dxb);
       dxb=dxb+1;
   }  
   return;
}
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int dxa = 0;
    int dxb = 0;
    vector<int> ans;
    while(dxb<B.size() && dxa<A.size()){
        if(A[dxa]==B[dxb] && ans[ans.size()-1] != A[dxa]){
            ans.push_back(A[dxa]);
            dxa++;
            dxb++;
        } 
        else if(A[dxa]>B[dxb]) dxb++; 
        else if(A[dxa]<B[dxb]) dxa++;
        else{
            dxa++;
            dxb++;
        }
    }
    return ans;

}
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int dxa = 0;
    int dxb = 0;
    vector<int> ans;
    while(dxb<B.size() && dxa<A.size()){
        if(A[dxa]==B[dxb]){
            ans.push_back(A[dxa]);
            dxa++;
            dxb++;
        } 
        else if(A[dxa]>B[dxb]) dxb++; 
        else dxa++;
    }
    return ans;

}
0, 0, 0, o0, t0, t1, t1, t1, t1, t1 
2
int Solution::solve(vector<int> &A, int B) {
    int o = 0;
    int t = 1;
    int temp = B;
    int maxsize = 0;
    if(A[0]==0 && temp>0) temp--;
    for(o;o<A.size();o++){
 
        while(t<A.size()){
            if(temp>0 && A[t]==0){
                temp--;
                t++;
            }else if(A[t]==1) t++;
            else{
                break;
            }
        }
        
        int x = t-o;
        maxsize = max(maxsize,x);
        if(t==A.size()) return maxsize;
        // else{
        //     if(A[t-1]==0) temp++;
        // }
        while(A[o]==1){
            o++;
        }
        temp++;
        // if(o==t-2){ 
        //     if(A[t]==0) temp++;
        //     t++;
        // }
    }
    return maxsize;
}

int main() {
    // int A =
    vector<int> C = { -4, 3 };
    vector<int> ans = {-2, -2};
    merge(ans,C);
    cout<<ans[0]<<ans[1];
}
