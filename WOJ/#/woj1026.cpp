#include<stdlib.h>
#include<stdio.h>
#define MAX 1005
int main(){
    int t,n,c,temp,m,k;
    int d[2][MAX];
    scanf("%d",&t);
    c=1;
    while(c<=t){
        m=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp=0;
                scanf("%d",&d[i%2][j]);
                if(0!=i){
                    k=(i-1)%2;
                    temp=d[k][j];
                    if(0!=j)
                        temp=temp>=d[k][j-1]?temp:d[k][j-1];
                    if(j!=n-1)
                        temp=temp>=d[k][j+1]?temp:d[k][j+1];
                }
                d[i%2][j]+=temp;
            }        
        }
        m=0;
        k=(n-1)%2;
        for(int i=0;i<n;i++){
            m=m>=d[k][i]?m:d[k][i];      
        }
        printf("Case %d:\n",c);
        printf("%d\n",m);
        if(c!=t)
            printf("\n");                
        c++;    
    }
    return 0;
}