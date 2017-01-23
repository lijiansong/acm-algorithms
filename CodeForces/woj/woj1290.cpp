/*
    Name: 
    Copyright: 
    Author: 
    Date: 28/12/15 06:52
    Description: woj1290
    ц╟ещеепР 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,count=0,i,j,temp;
    int num[10001];
    while(cin>>n&&n!=0)
    {
        for(i=0;i<n;i++)
            cin>>num[i];
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
            {
                if(num[j]>num[j+1])
                {
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                    count++;
                }
            }
            cout<<count<<endl;
            count=0;
    }
    return 0;
}