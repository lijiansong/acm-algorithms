/*
    Name: 
    Copyright: 
    Author: 
    Date: 29/12/15 05:07
    Description: woj1006
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int > vec[200001];
bool visited[200001];
struct Node
{
    int a,l;
    Node(int _a,int _b):a(_a),l(_b){}
};
int test(int s, int e)
{
    memset(visited, false,sizeof(visited));
    visited[s] = true;
    queue<Node> que;
    que.push(Node(s, 0));
    while(!que.empty()) 
    {
        Node tmp = que.front();
        que.pop();
        if(tmp.a == e) 
        {
            if(tmp.l >= 1) 
            return tmp.l - 1;
            return tmp.l;
        }
        for(vector<int>::iterator it = vec[tmp.a].begin(); it != vec[tmp.a].end(); it++) 
        {
            if(!visited[*it]) 
            {
                visited[*it] = true;
                que.push(Node(*it, tmp.l + 1));
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            vec[i].clear();
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            int count=test(a,b);
            cout<<count<<endl;
        }
    }
    return 0;
}