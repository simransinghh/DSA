#include <bits/stdc++.h>
using namespace std;
int Solution::isValidSudoku(const vector<string> &A) {
    unordered_map<int, unordered_set<char>> row, col, sec;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].length(); j++){
            if(A[i][j] != '.'){
                if(row[i].find(A[i][j]) != row[i].end() || col[j].find(A[i][j]) != col[j].end())
                    return 0;
                int s = (j/3)+10*(i/3);
                if(sec[s].find(A[i][j]) != sec[s].end())
                    return 0;
                row[i].insert(A[i][j]);
                col[j].insert(A[i][j]);
                sec[s].insert(A[i][j]);
            }
        }
    }
    row.clear(); col.clear(); sec.clear();
    return 1;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int target) {
    sort(A.begin(),A.end());
    set<vector<int>> res;
    int n=A.size();

    for(int i=0;i<n-3;++i){
        for(int j=i+1;j<n-2;++j){
            int st=j+1;
            int end=n-1;
            while(st<end){
                int summ=A[i]+A[j]+A[st]+A[end];
                if(summ==target){
                    res.insert({A[i],A[j],A[st],A[end]});
                    st++;
                    end--;
                }else if(summ<target){
                    st++;
                }else{
                    end--;
                }
            }
        }
    }
    vector<vector<int>> ans;
    for(auto i:res){
        ans.push_back(i);
    }
    return ans;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
            
                unordered_map<int,int> map;
                
                for (int i = 0; i < A.size(); i++){
                    
                    if(map.find(B - A[i]) != map.end()){
                        return {map[B - A[i]] + 1, i + 1};
                    }
                    else{
                        map.insert(make_pair(A[i], i));
                    }
                }
                return {};
}

vector<int> Solution::lszero(vector<int> &A) {
        vector<int> prefix(A.size());
        unordered_map<int,pair<int,int>> a;
        pair<int,int> maxx = make_pair(-1,-1);
        int difmax = 0;
        prefix[0] = A[0];
        a[A[0]] = make_pair(0,-1);
        if(A[0]==0){ 
                a[A[0]] = make_pair(0,0);
                difmax = 1;
                maxx = a[A[0]];
        }
        for(int i=1;i<A.size();i++){
                prefix[i] = A[i] + prefix[i-1];
                auto it = a.find(prefix[i]);
                if(prefix[i] == 0){
                        a[prefix[i]] = make_pair(0,i);
                        if(i+1>difmax){
                                difmax = i+1;
                                maxx = a[prefix[i]];
                        }
                }
                else if(it == a.end()){
                    a[prefix[i]] = make_pair(i,-1);
                    // cout<<i<<" "<<a[prefix[i]].first<<endl;
                }
                else{
                        pair<int,int> z = a[prefix[i]];
                        if(z.second == -1) z.first++;
                        z.second = i;
                        a[prefix[i]] = z;
                        // cout<<i<<" match "<<a[prefix[i]].first<<a[prefix[i]].second<<endl;
                        if(z.second - z.first + 1 > difmax){
                                difmax = z.second - z.first + 1;
                                maxx = a[prefix[i]];
                                // cout<<difmax<<" "<<maxx.first<<maxx.second<<endl;
                        }      
                }
        }
        vector<int> sub;
        if(difmax==0) return sub;
        // cout<<difmax<<" "<<maxx.first<<maxx.second<<endl;
        for(int i = maxx.first;i<=maxx.second;i++){
            sub.push_back(A[i]);
        }
        return sub;
}


int Solution::colorful(int A) {
    unordered_map<int, int> map;
    int acc, a;
    
    while(A){
        int acc = 1;
        int a = A;
        while(a){
            acc *= a % 10;
            a /= 10;
            if(map[acc] == 1) return 0;
            map[acc] = 1;
        }
        A /= 10;
    }
    return 1;
}


unordered_map<int,int> multiply;
vector<int> void subseqproduct(int no ,int product){
        if(no<10){
                multiply[no]++;
                return;
        }
        int n = no%10;
        no /= 10;
        subseqproduct(no,n,product);
        for(auto p : multiply){
                multiply[p.first*n]++;
        }
        multiply[n]++;
        return;
}
int Solution::colorful(int A) {
        for(auto p : multiply){
                if(p.second>1) return 0;
        }
        return 1;
}


int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
