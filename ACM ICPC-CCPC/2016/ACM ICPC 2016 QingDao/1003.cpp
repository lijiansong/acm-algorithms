#include <iostream>
#include <string>
#include <vector>
#include <cctype>
//#include<sstream>
#pragma warning(disable:4996)
using namespace std;
//typedef pair<int, char> P;//记录索引和字母值
int n;
vector<string> words;
vector<int> flag;
string str="";
string init(const string& s)//初始归一化为小写
{
	string ans = s;
	for (int i = 0; i < ans.length(); ++i)
	{
		if (isupper(ans[i]))
		{
			//P t = make_pair(i, ans[i]);
			flag.push_back(i);
		}
		ans[i] = tolower(ans[i]);
	}
	return ans;
}
string restore(const string& s)//大写还原
{
	string ans = s;
	for (int i = 0; i < flag.size(); ++i)
	{
		if (ans[flag[i]]!='*')
		{
			ans[flag[i]]=toupper(ans[flag[i]]);
		}
	}
	return ans;
}
void solve()
{
	for (int i = 0; i < words.size(); ++i)
	{
		int pos = str.find(words[i], 0);
		while (pos != -1)
		{
			for (int index = pos; index < pos + words[i].length(); ++index)
			{
				str[index] = '*';
			}
			int offset = pos + 1;
			pos = str.find(words[i], offset);
		}
	}
	str = restore(str);
	cout << str << endl;
}
int main()
{
	freopen("1003.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		string temp1;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp1;
			words.push_back(temp1);
			temp1 = "";
			cin.get();
		}
		//words.clear();
	}
	getline(cin, str);
	str = init(str);
	solve();
	return 0;
}
