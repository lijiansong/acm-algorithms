#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int flag[MAX],num[101];;

int main(void){
    int n,t,i,j,k;
    int countx,counta,count;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      if(n>1){
        for(i=0;i<MAX;i++)
            flag[i]=-1;
        j=0;
        countx=0;
        counta=0;
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);            
            if(flag[num[i]]!=-1){
                    count=0;
                    for(k=flag[num[i]];k<=i;k++)
                        if(num[k]!=-1)
                              count++;
                      if(i%2==0)
                        countx +=count;
                    else
                        counta +=count;
                    for(k=flag[num[i]];k<=i;k++)
                        num[k]=-1;
                    }
            else
                    flag[num[i]]=i;                                      
            }
        if(countx>counta)
            printf("xay\n");
        else
            printf("amr\n");
      }
    }
    //system("pause\n");
    return 0;          
    }