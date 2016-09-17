#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int n;
vector<string> words;
string str;
void solve()
{
	for(int i=0;i<words.size();++i)
	{
		int pos=str.find(words[i],0);
		while(pos!=-1)
		{
			for(int index=pos;pos<pos+words[i].length();++index)
			{
				str[index]='*';
			}
			int offset=pos+1;
			pos=str.find(words[i],offset);
		}
	}
	cout<<str<<endl;
}
int main()
{
	freopen("1003.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string temp1;
		for(int i=0;i<n;++i)
		{
			cin>>temp1;
			words.push_back(temp1);
			temp1="";
		}
		getline(cin,str); 
		solve();
		words.clear();
	}
	return 0;
} 
