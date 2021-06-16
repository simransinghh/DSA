#include <bits/stdc++.h>
using namespace std;

string phone[10] = { "0",   "1",   "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> Solution::letterCombinations(string A) {
        vector<string> w;
        for(int i = 0;i<A.length();i++){
                int x = A[i]-'0';
                A.erase(0,1);
                w = letterCombinations(A);
                if(w.empty()){
                        for(int j=0;j<phone[x].length();j++){
                                w.push_back(phone[x][j]);
                        }
                }
                else{
                        for(int k=0;k<w.size();k++){
                                for(int j=0;j<phone[x].length();j++){
                                        w[k] = phone[x][j] + w[k];
                                }
                        }

                }
        }
        return w;
}


vector<vector<int>> subs(vector<int> A,int idx){

        vector<vector<int> ans;
        if(idx>=A.size()) return ans;
        for(int i=idx;i<A.size();i++){
                if(i>0 && A[i]==A[i-1] && i != idx) continue;
                vector<vector<int> x = subs(A,i+1);
                if(x.empty()){
                        vector<int> z ={i};
                        vector<int> q ={};
                        ans.push_back(q);
                        ans.push_back(z);
                }
                else{
                        for(int j=0;j<x.size();j++){
                                ans.push_back(x[j]);
                                x[j].insert(x[j].begin(),i);
                                ans.push_back(x[j]);
                        }
                }

        }
        return ans;

}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {

        sort(A.begin(),A.end());
        vector<vector<int>> as = subs(A,0);
        sort(as.begin(),as.end);
        return as;


}


void comb(int A,int B,vector<vector<int>>&ans,vector<int>&res,int l)
{
    if(res.size()==B)
    {   
        ans.push_back(res);
        return;
    }
    for(int i=l;i<=A;i++)
    {
        res.push_back(i);
        comb(A,B,ans,res,i+1);
        res.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> arr;
    vector<int> res;
    vector<vector<int>> ans;
    comb(A,B,ans,res,1);
    return ans;
}
bool combo(int A,int B,int idx, vector<vector<int>>& ans){
        vector<vector<int>> x;
        if(B==0){
                vector<int> q;
                x.push_back(q);
                return true;
        }
        if(B>0 && idx>A){
                return false;
        }
        bool c = false;
        for(int i=idx;i<=A;i++){
            bool f = combo(A,B-1,i+1,x);
            if(f){
                    c = true;
                    if(x.empty()){
                        vector<int> q;
                        q.push_back(i);
                        ans.push_back(q);   
                    }
                    else{
                            for(int j=0;j<x.size();j++){
                                x[j].insert(x[j].begin(),i);
                                ans.push_back(x[j]);
                            }
                    }     
                
            }
            x.clear();
        }
        return c;
}
vector<vector<int>> Solution::combine(int A, int B) {
        vector<vector<int>> a;
        bool c = combo(A,B,1,a);
        return a;
}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
