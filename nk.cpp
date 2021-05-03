#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,size = 0;
    cin>>n>>k;
    priority_queue<long long> pq;
    for(int i = 0 ; i<n ;i++){
        int a;
        cin>>a;
        if(a==1){
            int x,y;
            cin>>x>>y;
            long long dist = x*x + y*y;
            pq.push(dist);
            size++;

        }
        else if(a==2){
            while(size>k){
                pq.pop();
                size--;
            }
            cout<<pq.top()<<endl;
        }
        else{
            i--;
            continue;
        }
    }
}
