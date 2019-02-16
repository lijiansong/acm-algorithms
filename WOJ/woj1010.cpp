/*
    Name: 
    Copyright: 
    Author: 
    Date: 28/12/15 10:34
    Description: woj1010
    这题比较坑爹，总是Runtime Error(Segment Fault) 
    这篇博客分析得不错
    http://blog.csdn.net/stormdpzh/article/details/7741043 
*/
#include<iostream>
#define N 1005
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int find(int num[],int k){
    int max = num[0];
    rep(i, k)
    {
        if (num[i]>max)  max = num[i];
    }
    return max;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, data[N];
    while (cin>>n&&n!=0)
    {
        rep(i, n)
            cin>>data[i];        
        int max = find(data,n);
        max = max % 2006;
        if (max < 0) max += 2006;
        int ans=max;
        rep(i, n-1)
        {
            ans *= 2;
            ans %= 2006;
        }
        cout<<ans<<endl;
    }
}