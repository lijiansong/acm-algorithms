#include <iostream>
#include <string.h>
using namespace std;
int N,t[50][50];
char m[50][5],c;
int main()
{
    while(cin>>N)
    {
        memset(t,sizeof(t),0);
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                cin>>m[i];
                c=m[i][0];
                if(c=='T')t[i][j]=10;
                else if(c=='J') t[i][j]=11;
                else if(c=='Q') t[i][j]=12;
                else if(c=='K') t[i][j]=13;
                else if(c=='A') t[i][j]=1;
                else t[i][j]=c-'0';
            }
        }
        for(int i=1;i<=N;i++)
            for(int j=N;j>=1;j--)
            t[i][j]=max(t[i][j+1],t[i-1][j])+t[i][j];
        cout<<t[N][1]<<endl;
    }
    }