#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxp=0x7ffff;
int P,a[maxp];
void solve()
{
	set<int> all;
	for(int i=0;i<P;++i) all.insert(a[i]);
	int n=all.size();
	
	int s=0,t=0,num=0;
	map<int,int> count;//知识点-出现次数 
	int res=P;
	for(;;)
	{
		while(t<P&&num<n)
		{
			if(count[a[t++]]++ ==0) ++num;
		}
		if(num<n) break;
		res=min(res,t-s);
		if(--count[a[s++]]==0) --num; 
	}
	printf("%d\n",res);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&P)!=EOF)
	{
		for(int i=0;i<P;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
} 
