#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<string,int> p;
string str="";
vector<p> phrase;

string init(const string &s)
{
	string ans=s;
	for(int i=0;i< ans.length();++i)
	{
		if((ans[i]==' '&& ans[i+1]==' ')||(ans[i]==' '&& ans[i+1]==',')||(ans[i]==' '&& ans[i+1]=='.'))
		{
			ans.erase(i,1);
		}
	}
	return ans;
}
bool cmp(const p &a,const p &b)
{
	return a.second > b.second;
}

void solve()
{
	string space=" ";
	string t="";
	int pos = str.find(space, 0);
	//cout<<pos<<endl;
	while(pos!=-1)
	{
		if((str[pos+1]!=',')&&(str[pos+1]!='.'))
		{
			for(int i=pos-1;i>=0;--i)
			{
				if((str[i]==',')||(str[i]=='.')||(str[i]==' '))
				{
					t+=str.substr(i+1,pos-i-1);
					//cout<<"--first t--"<<t<<endl;
					break;
				}
				/*t+=str.substr(i,pos-i-1);
				break;*/
			}
			
			int offset=pos+1;
			for(int i=offset;i<str.length();++i)
			{
				if(str[i]==' '||str[i]==','||str[i]=='.')
				{
					t+=str.substr(pos,i-pos);
					//cout<<"----second t---"<<t<<endl;
					p ph=make_pair(t,0);
					phrase.push_back(ph);
					cout<<t<<endl;
					t="";
					
					break; 
				}
				/*else
				{
					t="";
				}*/
			}
			pos = str.find(space, offset);
		}
		else
		{
			pos = str.find(space, pos+1);
		}
	}
	pos=0;
	
	for(int i=0;i<phrase.size();++i)
	{
		int index=str.find(phrase[i].first,0);
		while(index!=-1)
		{
			++phrase[i].second;
			int offset=index+1;
			index=str.find(phrase[i].first,offset);
		}
	}
	sort(phrase.begin(),phrase.end(),cmp);
	int times=phrase[0].second;
	vector<string> s;
	for(int i=0;i<phrase.size();++i)
	{
		if(phrase[i].second==times)
			s.push_back(phrase[i].first);
		else
			break;
	}
	
	sort(s.begin(),s.end());
	cout<<s[0]<<":"<<times<<endl;
	phrase.clear();
	s.clear();
}
int main()
{
	freopen("1003.txt","r",stdin);
	string temp;
	
	while(getline(cin,temp))
	{
		if(temp!="####")
		{
			str +=temp;
			str=init(str);
			str+=".";
			temp="";
		}
		else
		{
			solve();
			str="";
		}
	}
	return 0;
} 
