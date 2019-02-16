/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 13:44
    Description: woj1152
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int num[5000001];
int quick_sort(int a[],int p,int q,int k)
{
    if(p==q)
        return a[q];
    int temp=a[p];
    int i=p,j=q;
    while(i<j)
    {
        while(i<j&&temp<=a[j])
            j--;
        a[i]=a[j];
        while(i<j&&a[i]<=temp)
            i++;
        a[j]=a[i];
    }
    a[i]=temp;
    int h=i-p+1;
    if(h==k)
        return temp;
    else if(h<k)
        quick_sort(a,i+1,q,k-h);
    else if(h>k)
        quick_sort(a,p,i-1,k);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    memset(num,0,sizeof(num));
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
            cin>>num[i];
        int ans=quick_sort(num,0,n-1,k);
        cout<<ans<<endl;
    }
    return 0;
}