#include <iostream>
using namespace std;
int count(int n){
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    if(n<=0){
        return 0;
    }
    return count(n-1)+count(n-2);
}
int main() {
    int t,a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        cout<<"#"<<i+1<<" : "<<count(a)<<endl;
    }
}
