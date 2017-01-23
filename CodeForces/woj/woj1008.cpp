/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 10:43
    Description: woj 1008
    增广路算法求最大流
    参考《算法竞赛入门经典》第11章 网络流初步 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm> 
using namespace std;
#define N 210 
int m,n,k,a[N],flow[N][N],capacity[N][N],s,t,f,p[N];
void MaxFlow()
{
    queue<int> q;
    memset(flow,0,sizeof(flow));
    f=0;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=0xfffffff;
        q.push(s);
        while(!q.empty())//BFS寻找增广路径 
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=t;++v)
            {
                //找到新节点v 
                if(!a[v] && capacity[u][v] > flow[u][v])
                {
                    p[v]=u;q.push(v);//记录v的父节点，并加入队列 
                    a[v]=min(a[u],capacity[u][v]-flow[u][v]);
                }
            }
        }
        if(a[t]==0)break;//找不到则当前流即为最大流 
        for(int u=t;u!=s;u=p[u])//从汇点往回走 
        {
            flow[p[u]][u]+=a[t];//更新正向流量 
            flow[u][p[u]]-=a[t];//更新反向流量 
        }
        f+=a[t];//更新从s流出的总流量
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(cin>>m>>n)
    {
        memset(capacity,0,sizeof(capacity));
        s=0;
        t=m+n+1;
        f=0;
        int ani=m+1,temp;
        for(i=1;i<=m;++i)
        {
            for(j=0;j<n;++j)
            {
                cin>>temp;
                if(temp==1)
                    capacity[i][ani+j]=1;
                capacity[ani+j][t]=1;
            }
        }
        cin>>k;
        for(i=1;i<=m;++i)
        {
            capacity[0][i]=k;
        }
        MaxFlow();
        if(f==n)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}