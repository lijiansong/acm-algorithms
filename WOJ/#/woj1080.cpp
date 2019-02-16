#include<stdlib.h>
#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        if(n%14==0)
            printf("snoopy wins the game!\n"); 
        else
            printf("flymouse wins the game!\n");
            t--; 
    }
    return 0;  
}