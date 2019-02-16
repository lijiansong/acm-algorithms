#include<stdlib.h>
#include<stdio.h>
char buffer[128];
int length;
int main(){
    int a;
    int T;
    
    scanf("%d",&T);
    while(T--){
      scanf("%d",&a);
      length=126;
      if(a==0) buffer[length--]='0';
      buffer[127]='\0';
      
      while(a!=0){
          if(a>0)
            switch(a%3){
            case 0: buffer[length--]='0'; a=a/3; break;
            case 1: buffer[length--]='1'; a=(a-1)/3; break;
            case 2: buffer[length--]='-'; a=(a+1)/3; break;    
            }
          else
            switch(-a%3){
            case 0: buffer[length--]='0'; a=a/3; break;
            case 1: buffer[length--]='-'; a=(a+1)/3; break;
            case 2: buffer[length--]='1'; a=(a-1)/3; break;
          }
      }
      puts(buffer+length+1);
    }
    return 0;
}