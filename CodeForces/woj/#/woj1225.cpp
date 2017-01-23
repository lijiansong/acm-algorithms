#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=100000;

int vis[maxn+10];
int n,k;

struct node{
    int x,c;
};

int BFS(){
    queue<node> q;
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    node cur,next;
    cur.x=n,cur.c=0;
    vis[cur.x]=1;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0)
                next.x=cur.x-1;
            else if(i==1)
                next.x=cur.x+1;
            else
                next.x=cur.x*2;
            next.c=cur.c+1;
            if(next.x==k)
                return next.c;
            if(next.x>=0 && next.x<=maxn && !vis[next.x]){
                vis[next.x]=1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main(){

    //freopen("input.txt","r",stdin);

    while(~scanf("%d%d",&n,&k)){
        if(n>=k){
            printf("%d\n",n-k);
            continue;
        }
        printf("%d\n",BFS());
    }
    return 0;
}