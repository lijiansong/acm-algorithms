/*
    Name: 
    Copyright: 
    Author: 
    Date: 30/12/15 22:41
    Description: woj1003 
    Ö±½ÓÄ£Äâ 
*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char *name[13]={"Adam","Seth","Enosh","Kenan","Mahalalel","Jared","Enoch","Methuselah","Lamech","Noah","Shem","Ham","Japheth"}; 
    int order[13]={1,2,3,4,5,6,7,8,9,10,11,11,11}; 
    int age[9]={930,912,905,910,895,962,365,969,777};
    char man1[50],man2[50];
    while(cin>>man1>>man2)
    {
        int i=0,j=0,x=0,y=0;
        for(i=0;i<13;i++)
            if(!strcmp(name[i],man1))
                x=i;
        for(j=0;j<13;j++)
            if(!strcmp(name[j],man2))
                y=j;
        if(order[x]<order[y])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
            
        if(x>8||y>8)
            cout<<"No enough information"<<endl;
        else
        {
            if(age[x]>age[y])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}