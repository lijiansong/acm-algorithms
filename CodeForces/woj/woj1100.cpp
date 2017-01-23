/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 13:44
    Description: woj1100
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char* name[8]={"littleken","knuthocean","dongfangxu","zap","kittig","robertcui","forest","flirly"};
    char top1[]={'l','k','d','z','k','r','f','f'};
    char top2[]={'i','n','o','a','i','o','o','l'};
    int next[]={9,10,10,3,6,9,6,6};
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        string str;
        cin>>str;
        int max=0,index=0,ans[8]={0};
        for(string::iterator it=str.begin();it!=str.end();)
        {
            for(int i=0;i<8;i++)
            {
                if(*it==top1[i]&&*(it+1)==top2[i])
                {
                    it+=next[i];
                    ans[i]++;
                    break;
                }
            }
        }
        for(int i=0;i<8;i++)
        {
            if(max<ans[i])
            {
                max=ans[i];
                index=i;
            }
        }
        cout<<name[index]<<endl;
    }
    return 0;
}