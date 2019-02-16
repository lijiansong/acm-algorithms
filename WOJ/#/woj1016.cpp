#include <stdio.h> 
#include <stdlib.h> 

#define MAXN 1010 

typedef struct node // 定义点的信息,x,y为坐标 
{ 
    int x,y; 
} Node; 

Node s[MAXN],r[MAXN];  // s,r分别为升序和降序后点的信息 
int n; 

int cmp1(const void *a,const void *b)  // 升序快排判断 
{ 
    Node *aa=(Node *)a; 
    Node *bb=(Node *)b; 
    return((aa->y==bb->y)?(aa->x-bb->x):(aa->y-bb->y)); 
} 

int cmp2(const void *a,const void *b)  // 降序快排判断 
{ 
    Node *aa=(Node *)a; 
    Node *bb=(Node *)b; 
    return((aa->y==bb->y)?(aa->x-bb->x):(bb->y-aa->y)); 
} 

int check() // 判断函数,对称返回1,否则返回0 
{ 
    int i,k,sum; 
    k=n/2+1; 
    sum=s[0].y+r[0].y;  // y最大与y最小值和 
    for(i=0;i<k;i++)    // 判断是否对称 
    { 
        if(s[i].y+r[i].y!=sum) return(0);  // 两点不对称的情况 

        if(s[i].x!=r[i].x) return(0);      // 关于y对称但是x不一样 
    } 
    return(1); 
} 

int main() 
{ 
    int i; 
    while(scanf("%d",&n)!=EOF) 
    { 
        for(i=0;i<n;i++)    // 读入数据并复制 
        { 
            scanf("%d%d",&s[i].x,&s[i].y); 
            r[i]=s[i]; 
        } 
        qsort(s,n,sizeof(s[0]),cmp1);  // 对s进行升序快排 
        qsort(r,n,sizeof(r[0]),cmp2);  // 对r进行降序快排 
        if(check()==1) printf("YES\n"); // 判断 
        else printf("NO\n"); 
    } 
    return(0); 
}