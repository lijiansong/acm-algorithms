#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<math.h>  
using namespace std;  
  
/*int a[50005];  

int l,n,m;  
  
int b_s(int l,int r)  
{  
    int mid;  
    while(l<=r)  
    {  
        mid=(l+r)/2;  
        int cnt=0,last=0;  
        for(int i=1; i<=n+1; i++)  
            if(mid>=a[i]-a[last]) cnt++;  
            else last=i;  
        if(cnt>m)  
            r=mid-1;  
        else  
            l=mid+1;  
    }  
    return l;  
}  
  
int main()  
{
	freopen("in.txt","r",stdin);
    scanf("%d%d%d",&l,&n,&m);
    a[0]=0;
    a[n+1]=l;
    for(int i=1; i<=n; i++)  
        scanf("%d",&a[i]);  
    sort(a,a+n+1);  
    printf("%d\n",b_s(0,l));  
  
} */
/*const int INF=0x7fffffff;
int L,N,M;
int p[50009];
bool c(int n)
{
    int last=0;
    for(int i=0;i<=N-M;i++)
	{
        if(last==N+1)return 0;
        int cur=last+1;
        while(last<N+1&&p[cur]-p[last]<n)
		{
            cur++;
            if(cur==N+2)return 0;
        }
        last=cur;
    }
    return 1;
}
int main()
{
	freopen("in.txt","r",stdin);
    cin>>L>>N>>M;
    for(int i=1;i<=N;i++)
	{
        scanf("%d",&p[i]);
    }
    p[0]=0;
    p[N+1]=L;
    sort(p,p+N+2);
//    for(int i=0;i<=N+1;i++){
//        cout<<p[i]<<" ";
//    }
//    cout<<endl;
    int l=0,r=L+1,mid;
    while(r-l>1)
	{
        mid=(l+r)/2;
        if(c(mid))
		{
            l=mid;
        }
        else
		{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}*/
int a[50000+5];


int main()
{
	freopen("in.txt","r",stdin);
    int l,n,m;
    while(scanf("%d%d%d",&l,&n,&m)==3)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=0;a[n+1]=l;
        sort(a+1,a+1+n);
        int minn=a[1]-a[0],maxx=l;
        for(int i=1;i<=n+1;i++) minn=min(minn,a[i]-a[i-1]);
        int mid=(minn+maxx)>>1;
        while(minn<=maxx)  //注意这里是<=
        {
            int cnt=-1;
            int s=0;
            for(int i=1;i<=n+1;i++)
            {
                s+=a[i]-a[i-1];
                if(s>=mid)
                {
                    cnt++;
                    s=0;
                }
            }
            if(cnt<n-m) maxx=mid-1;
                else minn=mid+1;
            mid=(minn+maxx)>>1;
        }
        printf("%d\n",mid);
    }
} 
