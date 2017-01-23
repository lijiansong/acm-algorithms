#include<stdio.h>

#define M 1125

int prime[M]={2,3,5,7,11};
int dp[M][50];
int num=5;

int judge(int n){
    int i,j;
    for(i=0;prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0) return 0;
    }
    return 1;
}

void Init(){
    int gab,i,j;
    for(gab=2,i=13;i<M;i+=gab){
        gab=6-gab;
        if(judge(i)) {
            //printf("%d==%d\n",num,i);
            prime[num++]=i;
        }
    }
}

int main(){
    int i,j,k;
    int sum,n;
    Init();
    dp[0][0]=1;  
    for(i=0;i<num;i++){          
for(j=M;j>=prime[i];j--){
            for(k=15;k>0;k--){
                dp[j][k]+=dp[j-prime[i]][k-1];
            }
        }
    }
    while(scanf("%d%d",&sum,&n),sum+n){
        printf("%d\n",dp[sum][n]);
    }
    return 0;
}