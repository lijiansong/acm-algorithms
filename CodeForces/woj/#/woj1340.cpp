#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        int i;
        if(a[0]>='a' && a[0]<='z') a[0]=a[0]-32;
        if(b[0]>='a' && b[0]<='z') b[0]=b[0]-32;
        for(i=1;i<a.size();i++)
        {
          if(a[i]>='A' && a[i]<='Z') a[i]=a[i]+32;
        }
        for(i=1;i<b.size();i++)
        {
          if(b[i]>='A' && b[i]<='Z') b[i]=b[i]+32;
        }
        cout<<b<<' '<<a<<endl;
    }
    return 0;
}