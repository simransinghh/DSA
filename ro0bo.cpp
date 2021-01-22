#include <iostream>
using namespace std;
int robot(int x,int y,int arr[][5],bool power,int h){
    if(x<0 || y<0 || y>4){
        return 0;
    }
    int sum1,sum2,sum3,sum,add;
    if(x==h)add = 0;
    else if(arr[x][y]==-1 && power==true){
        power = false;
        add = 0;
    }
    else{
        add = arr[x][y];
    }
    sum1 = robot(x-1,y,arr,power,h);
    sum2 = robot(x-1,y+1,arr,power,h);
    sum3 = robot(x-1,y-1,arr,power,h);
    return max(sum1,max(sum2,sum3)) + add;
  
}
int main() {
    int t,h;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>h;
        int arr[h][5];
        for(int k=0;k<h;k++){
            for(int l=0;l<5;l++){
                cin>>arr[k][l];
            }
        }
        cout<<robot(h,2,arr,true,h)<<endl;
    }

}
