#include <bits/stdc++.h>
using namespace std;

int Solution::solve(string A) {
    int i=0;
    stack<int> s;
    while(i<A.length()){
        if(A[i]==')'){
            if(s.empty()) return 0;
            while(!s.empty() && A[s.top()]!='('){
                s.pop();
            }
            if(s.empty()) return 0;
            else{
                s.pop();
                i++;
            }
        }
        else if(A[i]=='('){
            s.push(A[i]);
            i++;
        }
        else i++;
    }

    if(s.empty()) return 1;
    return 0;
}
By looking at examples we can see that the above simplification process just
behaves like a stack. Whenever we encounter any file’s name, we simply push 
it into the stack. when we come across ” . ” we do nothing. When we find “..”
in our path, we simply pop the topmost element as we have to jump back to
parent’s directory. 
When we see multiple “////” we just ignore them as they are equivalent to one
 single “/”. After iterating through the whole string the elements
  remaining in the stack is our simplified absolute path. We have to create
   another stack to reverse the elements stored inside the original stack and then store the result inside a string.

string Solution::simplifyPath(string A) {

    int i =0;
    string ans;
    stack<int> s;
    while(i<A.length()){
        if(A[i]=='/' && A[s.top] != A[i]){
            s.push(i);
            i++;
        }
        else if(A[i]=='.' && A[i+1]=='.'){
            s.pop();
            s.pop();
            i = i+2;
        }
        else if(A[i]=='.' || A[i]=='/'){
            i++;
        }
        else{
            s.push(i);
        }
    }
    while(!s.empty()){
        ans = A[s.top()] + ans;
        s.pop();
    }
    return ans;

}

int Solution::braces(string A) {
    int i =0;
    while(i<A.length()){
        if(A[i]==')'){
            if(s.empty()) return 0;
            else if(A[s.top()] == '(') return 0;
            else{
                while(!s.empty() && A[s.top()] != '('){
                    s.pop();
                }
                if(s.empty()) return 0;
                else s.pop();
            }
        }
        else s.push[i];
        i++;
    }
    if(!s.empty()) return 0;
    return 1;
}
vector<int> mini;
int minn;
int idx;
int siz;
vector<int> minis;
MinStack::MinStack() {
    mini.clear();
    minis.clear;
    idx = -1;
    siz = 0;
}

void MinStack::push(int x) {
    mini.push_back(x);
    minn = min(minn,x);
    siz++;
    idx++;
}

void MinStack::pop() {
    if(siz == 0){
        idx = -1;
        return;
    } 
    mini.pop_back();
    idx--;
    siz--;
    
}

int MinStack::top() {
    if(siz == 0) return -1;
    return mini[idx];
}

int MinStack::getMin() {
    if(siz == 0) return -1;
    vector<int> a = mini;
}



int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
