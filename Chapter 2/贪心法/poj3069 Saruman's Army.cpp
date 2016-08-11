#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1001;
int x[MAX_N],r,n;
void solve()
{
	sort(x,x+n);
	int ans=0;
	int left=0,index=0;
	//bool marked=false;
	while(index<n)
	{
		while(x[left]<=(x[index]+r))
			left++;
		
		ans++;
		index=left-1;
		//left++;
		
		while(x[left]<=(x[index]+r))
			left++;
		index=left;
		left++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		cin>>r;
		for(int i=0;i<n;++i)
			cin>>x[i];
		solve();
	}
	fclose(stdin);
	return 0;
} 

