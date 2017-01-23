#include<stdio.h>
#define MAXSIZE 10000
int main(){
    long int a[MAXSIZE][2],temp;
    int t,n,i,j,l,max;
    scanf("%d",&t);
    while(t>0){
        t--;
        l=0;
        scanf("%d",&n); 
        for(i=0;i<n;i++){
            scanf("%ld",&temp);
            if(0==i){
                a[i][0]=temp;
                a[i][1]=1;
                l+=1;
            }else{
                a[i][1]=0;
                for(j=0;j<l;j++){
                    if(temp==a[j][0]){
                        a[j][1]+=1;
                        break;
                    }
                }
                if(j==l){
                    a[j][0]=temp;
                    a[j][1]=1;
                    l+=1; 
                }          
            }
          // printf("i:%d,temp:%ld,l:%d,al:%ld,an:%d\n",i,temp,l,a[l-1][0],a[l-1][1]);        
        }
        i=0;
        max=0;
        while(i<l){
            max=max>=a[i][1]?max:a[i][1];
            i++;              
        }
        printf("%d\n",max);    
    }
    return 0;
}