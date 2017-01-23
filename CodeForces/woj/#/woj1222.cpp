#include <stdio.h>
#include <string.h>
#include <memory.h>
#define MAXSIZE 2048
int add[30];
int del[30];
char str[MAXSIZE];
int dp[MAXSIZE][MAXSIZE];
int min_num(int a,int b,int c,int d) {
    int temp;
    temp=a;
    if (b<temp)
        temp=b;
    if (c<temp)
        temp=c;
    if (d<temp)
        temp=d;
    return temp;
}
int main()
{
    int n,m,i,j;
    char c;

    scanf("%d%d",&n,&m);
    getchar();
    memset(dp,0,sizeof(dp));
    scanf("%s",&str);
    for (i=0;i<n;i++) {
        getchar();
        scanf("%c",&c);
        scanf("%d%d",&add[c-'a'],&del[c-'a']);
    }

    //i为子串的末尾坐标，j为子串的起始坐标
    for (i=0;i<m;i++) {
        for (j=i-1;j>=0;j--) {
            if (str[i]==str[j])
                dp[j][i]=dp[j+1][i-1];
            else
                dp[j][i]=min_num(dp[j+1][i]+add[str[j]-'a'],dp[j+1][i]+del[str[j]-'a'],dp[j][i-1]+add[str[i]-'a'],dp[j][i-1]+del[str[i]-'a']);
        }
    }
    printf("%d\n",dp[0][m-1]);
    return 0;
}