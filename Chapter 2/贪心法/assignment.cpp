#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
    int date;
    int score;
    int sd;
};
node subject[1005];

int cmp(node a,node b)
{
    //return a.date<b.date||a.date==b.date&&a.score>b.score;
    return a.score>b.score||a.score==b.score&&a.date<b.date;
    //return a.sd>b.sd;
}

int main()
{
	freopen("in.txt","r",stdin); 
    int t;
    int n;
    int s=0;
    int b[1005]={0};
    scanf("%d",&t);
    for(int j=0;j<t;j++)
	{
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
		{
            scanf("%d",&subject[i].date);
        }
        for(int i=1;i<=n;i++)
		{
            scanf("%d",&subject[i].score);
            subject[i].sd=0;
        }
        sort(subject+1,subject+n+1,cmp);
        for(int i=1;i<=n;i++)
		{
            for(int ii=subject[i].date;ii>0;ii--)
			{
                if(b[ii]==0)
				{
                    b[ii]=1;
                    subject[i].sd=1;
                    break;
                }
            }
            if(subject[i].sd==0)
			{
                s+=subject[i].score;
            }
        }
        printf("%d\n",s);
        s=0;
        memset(b,0,sizeof(b));
    }
    return 0;
}
