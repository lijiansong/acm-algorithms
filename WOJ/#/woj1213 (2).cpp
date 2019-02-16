#include<stdlib.h>
#include<stdio.h>
int main() 
{ int n; 
scanf("%d",&n); 
int x[n+1],y[n+1]; x[0]=0;y[0]=0; 
for (int i=1;i<=n;i++) { scanf("%d %d",&x[i],&y[i]); } 
long signed int result=0;
for (int i=1;i<=n-1;i++)
  { result += (x[i]*y[i+1]-x[i+1]*y[i]); } 
  result+= (x[n]*y[1]-y[n]*x[1]); 
  result /= 2;
  printf("%ld",result);
    return 0; }