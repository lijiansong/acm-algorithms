/*
    Name: 
    Copyright: 
    Author: 
    Date: 22/01/16 20:17
    Description: woj1420
    ²Î¿¼ http://acm.whu.edu.cn/blog/index.php?go=category_5 
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> F;
int Ans=0,M,N;
void Dfs(int Step,int Frac,int Tot)
{
    if(Step >= F.size())
    {
        if(Tot&1) 
            Ans -= (long long)(M/Frac);
        else
            Ans += (long long)(M/Frac);
        return;
    }
    Dfs(Step+1,Frac*F[Step],Tot+1);
    Dfs(Step+1,Frac,Tot);
}

void Count(int Num)
{
    int Cur = Num;
    F.clear();
    for(int i=2;i*i<=Num;i++)
        if(Cur%i == 0)
        {
            F.push_back(i);
            while(Cur%i == 0)
                Cur /= i;
        }
    if(Cur > 1) F.push_back(Cur);
    Dfs(0,1,0);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>M>>N;
        for(int i=1;i<=N;i++)
            Count(i);
        cout<<Ans<<'\n';
        Ans=0;
    }
    return 0;
}