#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	//cin.get();
	for(int i=0;i< str.length();++i)
	{
		str[i]=toupper(str[i]);
	}
	cout<<str<<endl;
	return 0;
}
