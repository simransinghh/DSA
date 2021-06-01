#include <bits/stdc++.h>
using namespace std;
#define MOD 10000003

vector<int> searchRange(const vector<int> &A, int B) {

    int r = A.size();
    int st = 0;
    int end = r-1;
    vector<int> ans={-1,-1};
    while(st<=end){
        int mid = (st+end)/2;
        if(A[mid]==B){
            if(A[mid+1] != B && ans[1] == -1) ans[1] = mid;
            else if(A[mid-1] != B && ans[0] == -1) {
                ans[0] = mid; 
                break;
            }
            else{
                end = mid -1;
            }
        }
        else if(A[mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    st = 0;
    end  = r-1;
    if(ans[0] == -1) return ans;
    if(ans[0] == ans[1] && ans[0] != -1) return ans;
     while(st<=end){
        int mid = (st+end)/2;
        if(A[mid]==B){
            if(A[mid+1] != B && ans[1] == -1){
                 ans[1] = mid;
                 break;
        }
            else{
                st = mid + 1;
            }
            
        }
        else if(A[mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    return ans;
}


int searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size();
    int c = A[0].size();
    int st = 0;
    int end = r-1;
    int thiss = -1;
    while(st<=end){
        int mid = (st+end)/2;
        if(A[mid][0]==B) return 1;
        else if(A[mid][0]>B) end = mid-1;
        else{
            if(A[mid+1][0] > B){
                thiss = mid;
                break;
            }
            st = mid + 1;
        }
    }
    st = 0;
    end = c-1;
    while(st<=end){
        int mid = (st+end)/2;
        if(A[thiss][mid]==B) return 1;
        else if(A[thiss][mid]>B) end = mid-1;
        else{
            st = mid + 1;
        }
    }
    return 0;
}



int maxtime(int A, vector<int> &C, int maxx){
    int s = C.size();
    int sum = 0;
    int newmax = -1;
    for(int i=0;i<s;i++){
        if(A==0) return -1;
        sum += C[i];
        if(sum>maxx){
            i--;
            sum = 0;
            A--;
        }else{
            if(newmax<sum) newmax = sum;
        }
    }
    return newmax;

}
int paint(int A, int B, vector<int> &C) {
    int s = C.size();
    int sum = 0;
    int maxx = 0;
    for(int i=0;i<s;i++){
        sum += C[i];
        if(C[i]>maxx) maxx = C[i];
    }
    cout<<((B % MOD) * (sum % MOD)) % MOD;
    return 1;
    // if(A>=s) return ((B % MOD) * (maxx % MOD)) % MOD;
    // if(A==1) return ((B % MOD) * (sum % MOD)) % MOD;
    // int st = maxx;
    // int end = sum;
    // int ans = sum + 1;
    // while(st<=end){
    //     int mid = (st+end)/2;
    //     int tempanns = maxtime(A,C,mid);
    //     if(tempanns == -1){
    //         st = mid + 1;
    //     }else{
    //         ans = min(ans,tempanns);
    //         end = tempanns - 1;
    //     }
    // }
    // if(ans == sum + 1) return -1;
    // return ((B % MOD) * (ans % MOD)) % MOD;
}


int sqrt(int A) {
    if(A==0) return 0;
    if(A==1) return 1;
    int start = 1;
    int end = A;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(A/mid < mid){
            end = mid - 1;
        }
        else if(A == mid*mid) {
            return mid;
        }
        else if(A>mid*mid){
            if(A/(mid+1)<(mid+1)){
                return mid;
            }else{
                 start = mid+1;
            }
        }
    }
    return mid;
}




int main() {
    int A =  1,B = 1000000;
    vector<int> C = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> ans = searchRange(C,10);
    cout<<ans[0]<<ans[1];
}
