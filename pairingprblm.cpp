#include<iostream>
using namespace std;
#define int long long int
int arr[31] = {0};
int pairing(int n){
	if(n==1 || n==2){
		arr[n]=n;
		return n;
	}
	if(arr[n] != 0){
		return arr[n];
	}
	return pairing(n-1) + ((n-1)*pairing(n-2));
}
int32_t main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		cout<<pairing(n)<<endl;
	}
	return 0;
}
