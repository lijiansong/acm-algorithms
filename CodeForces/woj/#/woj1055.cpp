#include<stdio.h>
#include<string.h>
#define MAX 210
int main(){
    char m[MAX],temp[20];
    int i=0;
    while(strcmp(gets(temp),"ENDOFINPUT")!=0){
        memset(m,0,sizeof(m));
        memset(temp,0,sizeof(temp));
        gets(m);
        i=0;
        while(m[i]){
            if(m[i]>='A'&&m[i]<='Z'){
                m[i]=(m[i]-44)%26+65;//-5-'A'+1-1+26=-44                        
            }
            i++;        
        }
        gets(temp);
        puts(m);                                      
    }
    return 0;  
}