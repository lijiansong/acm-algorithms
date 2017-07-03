#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N=2000;
char s[MAX_N];
int n;
void solve()
{
	int a=0,b=n-1;
	while(a<=b)
	{
		bool left=false;
		for(int i=0;a+i<b;++i)
		{
			if(s[a+i]<s[b-i])
			{
				left=true;
				break;
			}
			else if(s[a+i]>s[b-i])
			{
				left=false;
				break;
			}
		}
		if(left)
			putchar(s[a++]);
		else
			putchar(s[b--]);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		solve();
	}
	fclose(stdin);
	return 0;
} 
