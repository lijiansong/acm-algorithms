#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
using namespace std;

const int ROW = 10000 + 10;
const int COL = 10 + 5;
int n,m;
map<string, int> IDcache;
vector<string> Strcache;
vector<int> Text[ROW]; //保存处理后的文本，每个字符串都替换成一个编号
struct node
{
    int x,y;
    node(int x, int y):x(x),y(y) { }
    bool operator < (const node& r) const { return x<r.x || x==r.x&&y<r.y; }
};
map<node,int> data;

int ID_alloc(string str)
{
    if(IDcache.count(str)) return IDcache[str];
    Strcache.push_back(str);
    return IDcache[str] = Strcache.size()-1;
}

void read()
{
    string str;
    char ch = getchar();
    for(int i=0;i<n;i++)
    {
        for(;;)
        {
            ch = getchar();
            if(ch=='\n'||ch=='\r') {
                if(!str.empty()) Text[i].push_back(ID_alloc(str));
                str.clear();  break;
            }
            if(ch!=',') str += ch;
            else { Text[i].push_back(ID_alloc(str)); str.clear();}
         }
    }
}

void solve()
{
    int x,y,c1,c2;
    for(c1=0;c1<m;c1++)
    {
        for(c2=c1+1;c2<m;c2++)
        {
            data.clear();
            for(int r=0;r<n;r++)
            {
                x = Text[r][c1]; y = Text[r][c2];
                node p(x,y);
                if(!data.count(p)) data[p] = r;
                else{
                    cout<<"NO"<<endl;
                    cout<<data[p]+1<<" "<<r+1<<endl<<c1+1<<" "<<c2+1<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    //freopen("1592.txt","r",stdin);
    while(cin>>n>>m)
    {
        read();
        solve();
        for(int i=0;i<n;i++) Text[i].clear();
        IDcache.clear(); Strcache.clear();
        //data.clear();
    }
    return 0;
}
