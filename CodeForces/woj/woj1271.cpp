/*
    Name: 
    Copyright: 
    Author: 
    Date: 15/01/16 09:32
    Description: woj1271
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double Angle(double x1,double y1,double z1,double x2,double y2,double z2)
{
    double len1 = sqrt(x1*x1+y1*y1+z1*z1);
    double len2 = sqrt(x2*x2+y2*y2+z2*z2);  
    double cos = (x1*x2+y1*y2+z1*z2)/len1/len2;  
    return acos(cos);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,count=0;
    while(cin>>n&&n)
    {
        double *sx=new double[n];
        double *sy=new double[n];
        double *sz=new double[n];
        bool *flag=new bool[n];
        for(int i=0;i<n;++i)
        {
            cin>>sx[i]>>sy[i]>>sz[i];
            flag[i]=false;
        }
        cin>>m;
        double *tx=new double[m];
        double *ty=new double[m];
        double *tz=new double[m];
        double *psi=new double[m];
        for(int i=0;i<m;++i)
        {
            cin>>tx[i]>>ty[i]>>tz[i]>>psi[i];
            for(int j=0;j<n;++j)
            {
                if(psi[i]>Angle(tx[i],ty[i],tz[i],sx[j],sy[j],sz[j])&&!flag[j])
                {
                    count++;
                    flag[j]=true;
                }
            }
        }
        cout<<count<<endl;
        count=0;
        delete tx,ty,tz,psi,flag,sx,sy,sz;    
    }
    return 0;
}