#include<iostream>
using namespace std;
unsigned long int Max;
unsigned long int condi(unsigned long int n)
{
        if(n==1) return 1;
        else
        {
            if(n%2==0) return 1+condi(n/2);
            return 1+condi(3*n+1);
            }
        }
int main()
{
    unsigned long int n,m,i,k;
    while(cin>>n,n!=0)
    {
                      Max=0;
                      cin>>m;
                      for(i=n;i<=m;i++)
                      {
                                      k=condi(i);
                                      if(k>Max) Max=k;
                                      }
                      cout<<Max<<endl;
    }
    return 0;
}