#include <stdio.h>
int main(){
    long int n=0,result=0;
    while(scanf("%d",&n)==1){
        result=n*(n+1)*(n-1)/6+n+1;
        printf("%ld\n",result);
    }
    return 0;
}