#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=0x7ffffff;
int n,S,a[maxn];
void solve()
{
	int res=n+1;
	int s=0,t=0,sum=0;
	for(;;)
	{
		while(t<n&&sum<S) sum+=a[t++];
		if(sum<S) break;
		res=min(res,t-s);
		sum-=a[s++];
	}
	if(res>n) res=0;
	printf("%d\n",res);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&S)!=EOF)
	{
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
} 
