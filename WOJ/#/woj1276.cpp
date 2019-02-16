#include<iostream>
#include<stdio.h>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#define ll long long
#define oo 10000007
using namespace std;    
int way[1005],num; 
bool DFSID(int x,int step)
{ 
      int i;
      if (num>step) return false;
      if (way[num]==x) return true;
      if (way[num]<<(step-num)  < x) return false; // Ç¿Á¦¼ôÖ¦ 
      for (i=0;i<=num;i++)
      {
            num++;
            way[num]=way[num-1]+way[i];
            if (way[num]<=10000 && DFSID(x,step)) return true; 
            way[num]=way[num-1]-way[i];  
            if (way[num]>0 && DFSID(x,step)) return true;          
            num--;
      } 
      return false;    
}
int main()
{  
      int i,x;
      //freopen("input.txt","r",stdin); 
//freopen("output.txt","w",stdout);      
      while (~scanf("%d",&x) && x) 
      {
            for (i=0;;i++)
            {
                way[num=0]=1;
                if (DFSID(x,i)) break;
            }
            printf("%d\n",i);
      }
      return 0;
}