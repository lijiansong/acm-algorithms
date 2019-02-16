/*
    Name: 
    Copyright: 
    Author: 
    Date: 12/01/16 18:12
    Description: woj1036 
    模拟斐波那契数列和大数和 
*/
#include<iostream>
#include<stdio.h>
#include<string> 
using namespace std;
string Add(string Num1, string Num2)
{
    string Ans;
    int *a,*b,i,Max,Len,Len1,Len2,k;
    Len1=(int)Num1.length();
    Len2=(int)Num2.length();
    if (Len1>Len2) Len=Len1;
    else Len=Len2;
    Max=Len;
    a=new int[Len+1];
    for (i=0;i<=Len;i++) 
        a[i]=0;
    b=new int[Len];
    for (i=0;i<=Len-1;i++) 
        b[i]=0;
    k=0;
    for (i=Len1-1;i>=0;i--) 
        a[k++]=Num1[i]-'0';
    k=0;
    for (i=Len2-1;i>=0;i--) 
        b[k++]=Num2[i]-'0';
    for (i=0;i<=Len-1;i++)
    {
        a[i]=a[i]+b[i];
        if (a[i]>=10)
        {
            a[i]=a[i]-10;
            a[i+1]++;
        }
    }
    while (Len+1>Max || a[Len+1]==0) 
        Len--;
    for (i=Len+1;i>=0;i--) 
        Ans.append(1,a[i]+'0');
    delete a;
    delete b;
    return Ans;
}
string count(int n)
{
    if(n==1)
        return "1";
    else if(n==2)
        return "2";
    else if(n==3)
        return "4";
    else
    {
        string str_ans[n];
        str_ans[0]="1",str_ans[1]="2",str_ans[2]="4";
        for(int i=3;i<n;i++)
        {
            string temp=Add(str_ans[i-1],str_ans[i-2]);
            str_ans[i]=Add(temp,str_ans[i-3]);
        }
        string m=str_ans[n-1];
        //delete str_ans;
        return m;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0;
    string ans;
    while(cin>>n&&n!=0)
    {
        ans=count(n);
        cout<<ans<<endl;
    }
    return 0;
}