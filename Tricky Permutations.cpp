#include<iostream>
#include<set>

using namespace std;

set <string> ans;

void perm(string s,int i)
{
	if(s[i]=='\0')
	{
		ans.insert(s);
		return ;
	}

	for(int j=i;s[j]!='\0';j++)
	{
		swap(s[i],s[j]);
		perm(s,i+1);
		swap(s[i],s[j]);
	}
}

int main() {

	string str;
	cin>>str;

	perm(str,0);

	for(auto i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<endl;
	}



	return 0;
}
