/*
    Name: 
    Copyright: 
    Author: 
    Date: 22/01/16 22:00
    Description: woj1050
    最小生成树
    prim算法的实现 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=101;
int main()
{
    //freopen("in.txt","r",stdin);
    int t,matrix[N][N],num;
    int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>num;
        for(i=1;i<=num;++i)
            for(j=1;j<=num;++j)
                cin>>matrix[i][j];
        int sum=0,flag[N]={0};//flag[i]标识节点i是否已经被覆盖 
        flag[1]=1;//从第一个节点开始 
        for(k=1;k<num;++k)
        {
            int min=-1,min_weight;
            for(i=1;i<=num;++i)//选取下一个权值最小的节点
            {
                if(flag[i]==0&&(min==-1||matrix[1][i]<min))
                {
                    min=matrix[1][i];
                    min_weight=i;
                }
            }
            flag[min_weight]=1;
            for(i=1;i<=num;++i)
            {
                if(flag[i]==0&&matrix[1][i]>matrix[min_weight][i])
                {
                    matrix[1][i]=matrix[min_weight][i];
                }
            }
            sum+=matrix[1][min_weight];
        }
        cout<<sum<<endl;
    }
    return 0;
}