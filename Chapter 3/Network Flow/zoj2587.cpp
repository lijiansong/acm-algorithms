#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int SS = 805, TT = 806;
const int INF = 0x3fffffff;
int N, M, A, B;

struct Edge {
    int v, c, next;    
};
Edge e[30000];
int idx, head[810], lv[810];
int front, tail, que[810];
int vis[810];

void insert(int a, int b, int c) {
    e[idx].v = b, e[idx].c = c;
    e[idx].next = head[a];
    head[a] = idx++;
}

bool bfs() {
    memset(lv, 0xff, sizeof (lv));
    front = tail = lv[SS] = 0;
    que[tail++] = SS;
    while (front < tail) {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (!(~lv[v]) && e[i].c) {
                lv[v] = lv[u] + 1;
                if (v == TT) return true;
                que[tail++] = v;    
            }
        }
    }
    return false;
}

int dfs(int u, int sup) {
    if (u == TT) return sup;
    int tf = 0, f;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (lv[u]+1==lv[v] && e[i].c && (f=dfs(v, min(e[i].c, sup-tf)))) {
            tf += f;
            e[i].c -= f, e[i^1].c += f;
            if (tf == sup) return sup;    
        }
    }
    if (!tf) lv[u] = -1;
    return tf;
}

void dinic() {
    int ret = 0;
    while (bfs()) {
        ret += dfs(SS, INF);    
    }
//    printf("ret = %d\n", ret); 
}

void flood(int u, int &cnt) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        if (e[i].c && !vis[e[i].v])    {
            ++cnt;
            vis[e[i].v] = 1;
            flood(e[i].v, cnt);
        }
    }
}

void flood_r(int u, int &cnt) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        if (e[i^1].c && !vis[e[i].v])    {
            ++cnt;
            vis[e[i].v] = 1;
            flood_r(e[i].v, cnt);
        }
    }
}

bool query() {
    int cnta = 0, cntb = 0; // 分别为从两个方向进行搜索而计数
    memset(vis, 0, sizeof (vis));
    vis[SS] = vis[TT] = 1;
    flood(SS, cnta);
    memset(vis, 0, sizeof (vis));
    vis[SS] = vis[TT] = 1;
    flood_r(TT, cntb);
    return cnta + cntb == N;
}

int main() {
    while (scanf("%d %d %d %d", &N, &M, &A, &B), N|M|A|B) {
        int a, b, c;
        idx = 0;
        memset(head, 0xff, sizeof (head));
        insert(SS, A, INF), insert(A, SS, 0);
        insert(B, TT, INF), insert(TT, B, 0);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            insert(a, b, c), insert(b, a, c);
        }
        dinic();
        printf(query() ? "UNIQUE\n" : "AMBIGUOUS\n");
    }
    return 0;        
}
