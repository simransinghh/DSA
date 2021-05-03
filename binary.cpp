#include<bits/stdc++.h>
using namespace std;
#define int long long int
int binary(int idx,int arr[][90],int ans){
    //ans is to check if you need ending with 0 or 1 or their sum(2)
	if(idx==1){
		arr[0][1]=1;
		arr[1][1]=1;
		if(ans == 2){
			return 2;
		}else{
			return 1;
		}
	}


	int zero,one;
	if( arr[0][idx-1] == -1 ){
		zero = binary(idx-1,arr,0);
	}else{
		zero = arr[0][idx-1];
	}


	if( arr[1][idx-1] == -1 ){
		one = binary(idx-1,arr,1);
	}else{
		one = arr[1][idx-1];
	}


	arr[0][idx] = zero + one;
	arr[1][idx] = zero;
	

    if(ans == 0){
		return arr[0][idx];
	}
	if(ans == 1){
		return arr[1][idx];
	}
	return arr[0][idx]+arr[1][idx]; 

}
int32_t main() {
	int t;
	cin>>t;
	int arr[2][90];
		for(int j=0;j<2;j++){
			for(int k=0;k<90;k++){
				arr[j][k]=-1;
			}
		}
	for(int i=0;i<t;i++){	
		int a;
		cin>>a;
		cout<<binary(a,arr,2)<<endl;
	}
	return 0;
}
