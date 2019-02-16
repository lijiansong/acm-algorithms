#include <iostream>
using namespace std;
int cross(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}
int main()
{
    int n, i, x[103], y[103];
    cin>>n;
    for (i = 0; i < n; ++i) cin>>x[i]>>y[i];
    x[n] = x[0]; y[n] = y[0];
    int area = 0;
    for (i = 0; i < n; ++i) 
area += cross(x[i], y[i], x[i + 1], y[i + 1]);
    if (area < 0) area = -area;
    cout<<area / 2<<endl;
return 0;
}