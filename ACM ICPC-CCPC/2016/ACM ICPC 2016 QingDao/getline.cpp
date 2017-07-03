#include<iostream>
using namespace std;
string str="";
int n;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		string temp1;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp1;
			//words.push_back(temp1);
			temp1 = "";
			cin.get(); 
		}
		//words.clear();
	}
	getline(cin,str);
	cout<<str<<endl;
	return 0;
} 
