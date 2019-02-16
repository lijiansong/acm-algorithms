#include <stdio.h>
#include <string.h>
#define MAX 2005
char a[MAX],b[MAX];
int res[2][MAX];
int main(){
    int tc=0;
    scanf("%d",&tc);
    for(int ca=0;ca<tc;ca++){
        scanf("%s %s",a,b);
        int lengtha,lengthb;
        lengtha=lengthb=0;
        while(a[lengtha])lengtha++;
        while(b[lengthb])lengthb++;
        int lcsmax=0;
        for(int now=1;now<=lengtha;now++){
            for(int nowb=1;nowb<=lengthb;nowb++){
                if(a[now-1]==b[nowb-1]){
                    res[now%2][nowb]=res[(now+1)%2][nowb-1]+1;
                    if(res[now%2][nowb]>lcsmax) 
                        lcsmax=res[now%2][nowb];
                }else 
                    res[now%2][nowb]=0;
            }
        }
        printf("%d\n",lcsmax);
    }
    return 0;
}