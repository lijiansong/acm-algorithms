#include <stdio.h>
#define MAX 104
char c[MAX];
int mod(int a,int n){
    if(a%n==0) return n;
    if((a%n)>0) return a%n;
    else return a%n+n;
}
int main(){
    while(scanf("%s",c)){
                        if(c[0]=='$') break;
                        int i=0;
                        while(c[i]){
                                    c[i]=mod(c[i]-i-1-64,26)+64;
                                    i++;
                                    }
                        printf("%s\n",c);
                        }
    return 0;
}