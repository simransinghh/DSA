#include <bits/stdc++.h>
using namespace std;


int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int prefix = 0;          
    unordered_map<int, int> map; 

    for (int ele : A)
    {
        prefix_xor = prefix_xor ^ ele;
        if (prefix == B)
            count++;
        count += map[prefix ^ B];
        map[prefix]++;
    }

    return count;
}



int Solution::solve(vector<int> &A, int B) {
        int count = 0;
        unordered_map<int,int> bla;
        for(int i = 0;i<A.size();i++){
                int y = A[i]^B;
                auto it = bla.find(y);
                if(it == bla.end()){
                        bla[A[i]] = i;
                }else{
                        int idx = bla[A[i]];
                        bla[A[i]] = i;
                        A[idx]++;
                        int x = A[idx];
                        auto xt = bla.find(x);
                        if(xt != bla.end()){
                                if(xt->second > idx) bla[x] = idx;
                        }else{
                                bla[x] = idx;
                        }
                }
        }
}


vector<int> Solution::solve(vector<int> &A) {
        unordered_map<int,int> bla;
        for(int i = 0;i<A.size();i++){
                int y = A[i];
                auto it = bla.find(y);
                if(it == bla.end()){
                        bla[A[i]] = i;
                }else{
                        int idx = bla[A[i]];
                        bla[A[i]] = i;
                        A[idx]++;
                        int x = A[idx];
                        auto xt = bla.find(x);
                        if(xt != bla.end()){
                                if(xt->second > idx) bla[x] = idx;
                        }else{
                                bla[x] = idx;
                        }
                }
        }

        return A;
}
int Solution::diffPossible(const vector<int> &A, int B) {
        unordered_map<int,int> bla;
        for(int i = 0;i<A.size();i++){
                int x = A[i]+B;
                int y = A[i] - B;
                auto it = bla.find(x);
                auto yt = bla.find(y);
                if((it != bla.end() && it->second != i) || (yt != bla.end() && yt->second != i)){
                    // cout<<A[i]<<" "<<it->first<<endl;
                    return 1;
                }
                bla[A[i]] = i;
        }
        return 0;

}

int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
