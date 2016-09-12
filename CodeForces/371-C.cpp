#include<cstdio>
#include<algorithm>
using namespace std;
const long long m=10007;
int n;
long long a[10001];
int main()
{
	long long s=0,n,i,a[100000];
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		s+=a[i]*a[n-i-1];
		s%=m;
	}
	printf("%I64d",s);
	return 0;
}
