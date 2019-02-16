#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 5005
int main(){
    int t,l,x,y;
    double sum,s;
    char p[MAX];
    scanf("%d",&t);
    while(t>0){
        t--;
        scanf("%s",&p);
        l=0;
        y=0;    
        sum=0;
        s=0;
        x=0;      
        while(p[l]){
            if('R'==p[l]){
                x+=1;
                sum+=y;
                //printf("y:%d,sum:%f\n",y,sum);    
            }else{
                y+=1;      
            }
          //printf("l:%d,x:%d,y:%d,RU:%c,sum:%f\n",l,x,y,p[l],sum);    
            l++;                        
        }
      // printf("x:%d,y:%d,sum:%f\n",x,y,sum); 
        s=0.5*x*y-sum;
        //printf("%f",s);
        if(s>=0){
          // printf("%F",s);  
            s=round(s*1000)/(double)1000;
            printf("%.3f\n",s); 
        }else{
            s=round(-1*s*1000)/(double)1000;
            printf("-%.3f\n",s);  
        }
    }
    return 0;    
}