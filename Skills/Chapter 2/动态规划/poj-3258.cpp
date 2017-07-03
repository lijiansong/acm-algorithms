#include <iostream>  
#include <cstdio>  
#include <algorithm>  
using namespace std;
/*
http://blog.csdn.net/lyy289065406/article/details/6648558
*/
  
int L, N, M;  
int d[50005];  
  
bool cmp(int a, int b) 
{  
    return a < b;  
}  
  
int BSearch(int l, int h, int k) 
{  
    int m, last, cnt;  
    while (l <= h) 
    {  
        m = (l + h) >> 1;  
        last = cnt = 0;  
        for (int i = 1; i <= N + 1; i++) 
        {  
            if (m >= d[i] - d[last]) cnt++;  
            else last = i;  
        }  
        if (cnt > k) h = m - 1;  
        else l = m + 1;  
    }  
    return l;  
}  
  
int main()  
{
    freopen("in.txt","r",stdin); 
    scanf ("%d%d%d", &L, &N, &M);  
    d[0] = 0;  
    d[N+1] = L;  
    for (int i = 1; i <= N; i++)  
        scanf ("%d", &d[i]);  
    sort(d+1, d+1+N, cmp);  
    printf ("%d\n", BSearch(0, L, M));  
  
    return 0;  
}
