#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_ML = 10001;
const int MAX_MD = 10001;
const int MAX_N = 1001;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];
const int INF = 1000001;
int d[MAX_N];
int N, ML, MD;
void solve()
{
	fill(d, d + N, INF);
	d[0] = 0;
	for (int k = 0; k < N; ++k)
	{
		//i+1 to i weight is 0
		for (int i = 0; i + 1 < N; ++i)
		{
			if (d[i + 1] < INF)
				d[i] = min(d[i], d[i + 1]);
		}
		//AL to BL weight is DL
		for (int i = 0; i < ML; ++i)
		{
			if (d[AL[i] - 1] < INF)
				d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
		}
		//BD to AD weight is -DD
		for (int i = 0; i < MD; ++i)
		{
			if (d[BD[i] - 1] < INF)
				d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
		}
	}
	int res = d[N - 1];
	if (d[0] < 0)
	{
		res = -1;
	}
	else if (res == INF)
	{
		res = -2;
	}
	printf("%d\n", res);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d %d %d", &N, &ML, &MD) != EOF)
	{
		for (int i = 0; i < ML; ++i)
			scanf("%d %d %d", &AL[i], &BL[i], &DL[i]);
		for (int i = 0; i < MD; ++i)
			scanf("%d %d %d", &AD[i], &BD[i], &DD[i]);
		solve();
	}
	return 0;
}
