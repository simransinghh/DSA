#include <iostream>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void phonekey(string &ans, string no){
   if(no==""){
       cout<<ans<<endl;
       return;
   }
   int actualno = no[0]-'0';
   string tempp = no.substr(1);
   string temp = ans;
   for(auto i:table[actualno]){
       temp = temp + i;
       phonekey(temp,tempp);
       temp = ans;       
   }
}
int main() {
    string n;
    cin>>n;
    string ans="";
    phonekey(ans,n);
    return 0;
}
