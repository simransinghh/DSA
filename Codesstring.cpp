#include<iostream>
#include<string>
using namespace std;
bool first=true; 
void strcode(int idx,string arr,string *str,int st){

	if(arr[idx]==NULL){
		if(arr[idx]==NULL){
        if(first==false){ //if not first string then print , before printing the next string
            cout<<", ";
        }	
        cout<<*str; 
        first=false;  //since we printed the string it cant be first anymore
		return;
	}
	}
	int x = arr[idx] - '0';
	char x1 = char(x+96);
	*str+=x1; //updaed this because str[st] is not allocated 
	strcode(idx+1,arr,str,st+1);
    (*str).pop_back(); //added this kind of backtrack

	if(arr[idx+1]!=NULL){
		int y = (arr[idx+1] - '0') + (10)*(x) + 96;
		char y1 = char(y);
		if(y>=106&&y<122){ //updated this
            *str+=y1; //updaed this because str[st] is not allocated 
			strcode(idx+2,arr,str,st+1);
            (*str).pop_back(); //added this kind of backtrack
		}
	}
	
}
int main() {
	string arr,str;
	cin>>arr;
	cout<<'[';
	strcode(0,arr,&str,0);
	cout<<']';
	return 0;
}
