#include <iostream>
#include<stdio.h>
using namespace std; 
int main()
{
  int t,n,a[51];
  double p; 
  while(cin>>t)
  {
      for(int i=0;i<t;i++)
      {
      scanf("%d%%",&a[i]);
      p=a[i]/100.0;
      printf("%.2lf%\n",100*p*p/(1-2*p*(1-p)));
    }
  }
  return 0;
}