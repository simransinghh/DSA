#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin().A.end());
    if(B<0) B = B*(-1);
    int i = 0,l = 1;
    for(int j=0;j<A.size();j++){
        if(A[l] - A[i] == B) return 1;
        if(A[l] - A[i] < B) l++;
        if(A[l] - A[i] > B) i++;
    } 
    return 0;
}
int Solution::threeSumClosest(vector<int> &A, int target) {
    int n=A.size();
    sort(A.begin(),A.end());
    long  bestSum=INT_MAX,sum=0;
    for(int i=0;i<n-2;i++){
        int start=i+1,end=n-1;
        while(start<end){
            sum=long(A[i])+A[start]+A[end];
            if(abs(target-sum)<abs(target-bestSum))
                bestSum=sum;
            else if(sum>target)
                end--;
            else
                start++;
        }
    }
    return bestSum;
}
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    long  sum;
    for(int i=0;i<n-2;i++){
        int start=i+1,end=n-1;
        while(start<end){
            sum=long(A[i]+A[start]+A[end]);
            if(sum==0){
                vector<int> a;
                a.push_back(A[i]);
                a.push_back(A[start]);
                a.push_back(A[end]);
                ans.push_back(a);
            }
            else if(sum>0)
                end--;
            else
                start++;
        }
    }
    return ans;
}

int nTriang(vector<int> &A) {
    
    int n=A.size();
    sort(A.begin(),A.end());
    int ans;
    long long  sum;
    for(int i=0;i<n-2;i++){
        int start=i+1,end=n-1;
        sum=(long long)A[start]+(long long)A[end];
        int compare = A[i];
        int three = 0;
        while(start<end){
            if(sum>compare){
                three++;
                if(three==3){
                    ans++;
                    three = 0;
                    compare = A[i];
                    end--;
                }else if(three == 2){
                    compare = A[start];
                    sum = (long long)A[i]+(long long)A[end];
                }
                else if(three == 1){
                    compare = A[end];
                    sum = (long long)A[i]+(long long)A[start];
                }
            }
            else if(sum<=compare){
                start++;
                end = n-1;
                three = 0;
                compare = A[i];
            }
        }
    }
    return ans;
    
}
int Solution::nTriang(vector<int> &A) {
    int n=A.size(),ans=0,m=1e9+7;
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        if(A[i]==0) continue;
        for(int j=i+1;j<n-1;j++)
            ans=(ans+((lower_bound(A.begin(),A.end(),A[i]+A[j]))-(A.begin()+j+1)))%m;
    }
    return ans;
}
int main() {
    int A = -466;
    vector<int> C = {1,1,1};
    cout<nTriang(C);
}
