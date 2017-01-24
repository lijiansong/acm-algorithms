#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double pi=3.1415926;
int n,d;
std::vector<double> angle;
void solve()
{
	double area=0;
	for(int i=0;i<n;++i)
	{
		area+=0.5*d*d*sin(angle[i]*pi/180.0);
	}
	printf("%.3lf\n",area);
	angle.clear();
}
int main()
{
	double ang=0;;
	
	while(cin>>n>>d)
	{
		for(int i=0;i<n;++i)
		{
			cin>>ang;
			angle.push_back(ang);
		}
		solve();
	}
	return 0;
}