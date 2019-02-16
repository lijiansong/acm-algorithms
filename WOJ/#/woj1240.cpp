#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;
#define _PI acos(-1.0)
#define INF 1 << 10
#define esp 1e-6
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pill;
#define MAXD 10000 + 10
int n;
int dp[MAXD][4];
int vis[MAXD];
/*dp[i][0]代表结点i是服务器的时候*/
/*dp[i][1]代表结点i的父亲是服务器的时候*/
/*dp[i][2]代表结点i的儿子是服务器的时候*/
vector<int>G[MAXD];
void DP(int pos){
    vis[pos] = 1;
    dp[pos][0] = 1;
    dp[pos][1] = 0;
    dp[pos][2] = 1 << 20;
    vector<int>arr;
    for(int i = 0 ; i < G[pos].size() ; i++){
        int t = G[pos][i];
        if(!vis[t]){
            DP(t);
            arr.push_back(t);
            dp[pos][0] =  dp[pos][0] + min(dp[t][1],dp[t][0]);
            dp[pos][1] += dp[t][2];
        }
    }
    for(int i = 0 ; i < arr.size() ; i++){
        int t = arr[i];
        dp[pos][2] = min(dp[pos][2],dp[pos][1] - dp[t][2] + dp[t][0]);
    }
    return ;
}
int main(){
    while(scanf("%d",&n)){
        for(int i = 1 ; i <= n ; i++)
            G[i].clear();
        for(int i = 1 ; i < n ; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = 1 << 20;
        DP(1);
        memset(vis,0,sizeof(vis));
        ans = min(dp[1][0],dp[1][2]);
        printf("%d\n",ans);
        int next;
        scanf("%d",&next);
        if(next < 0)
            break;
    }
    return 0;
}