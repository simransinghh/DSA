#include<iostream>
using namespace std;
void balance(int n,int open,int close , char str[]){
	if(open==n && close==n){
		for(int i=0;i<2*n;i++){
			cout<<str[i];
		}
		cout<<endl;
		return;
	}
	if(open>close){
		str[open + close]=')';
		balance(n,open,close+1,str);
	}
		if(open<n){
		str[open + close]='(';
		balance(n,open+1,close,str);
	}
}
int main() {
	int n;
	cin>>n;
	char str[100];
	balance(n,0,0,str);
	return 0;
}
