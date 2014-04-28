// File Name: 2C.cpp
// Author: YangYue
// Created Time: Sat Apr 26 15:14:04 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 100005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int fa[111111][18];
int depth[111111];
LL sum[111111];
int et;
struct EDGE {
	int y, w;
	EDGE *Next;
	EDGE(){}
	EDGE(int y, int w, EDGE *Next) : y(y), w(w), Next(Next) {}
} *E[111111], edge[222222];
void addedge(int u, int v, int w) {
	edge[et] = EDGE(v, w, E[u]);
	E[u] = &edge[et++];
}
int lca(int x,int y)
{
	if(depth[x] < depth[y]) swap(x,y);
	int delta = depth[x]-depth[y];
	for(int i = 0;i < 18;i++)
	{
		if(delta&(1<<i)) x = fa[x][i];
	}
	for(int i = 17;i >= 0;i--)
	{
		if(fa[x][i] != fa[y][i]) { x = fa[x][i]; y = fa[y][i]; }
	}
	if(x != y) x = fa[x][0];
	return x;
}
int Queue[111111];
int build_lca(int root)
{
	int front = 0;
	int end = 0;
	Queue[end++] = root;
	fa[root][0] = 0; // -1 
	while(front != end)
	{
		int x = Queue[front++];
		for(EDGE* e = E[x];e;e = e->Next)
		{
			int y = e->y;
			if (y == fa[x][0]) continue;
			fa[y][0] = x;
			sum[y] = sum[x] + e->w;
			depth[y] = depth[x]+1;
			Queue[end++] = y;
		}
	}
	for(int i = 1;i < 18;i++)
		for(int j = 0;j < end;j++)
		{
			int x = Queue[j];
			fa[x][i] = fa[fa[x][i-1]][i-1];
		}
	return 0;

}
LL dis(int a, int b) {
	int LCA = lca(a, b);
	return sum[a] + sum[b] - 2 * sum[LCA];
}
PII a[MaxN];
int main()
{
	//freopen("in","r",stdin);

	
	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case %d: ", ++cas);

		et = 0;
		memset(E, 0, sizeof E);
		memset(sum, 0, sizeof sum);
		memset(depth, 0, sizeof depth);

		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int w; scanf("%d", &w);
			a[i - 1] = MP(w, i);
		}
		for (int i = 1; i < n; ++i) {
			int x, y, c; scanf("%d %d %d", &x, &y, &c);
			addedge(x, y, c);
			addedge(y, x, c);
		}
		build_lca(1);
		sort(a, a + n);
		int x = a[n-1].second, y = x;
		LL nowdist = 0;
		LL ans = 0;
		for (int i = n - 2; i >= 0; --i) {
			LL dist1 = dis(x, a[i].second);
			LL dist2 = dis(y, a[i].second);
			ans = max(ans, (LL) a[i].first * max(dist1, dist2));
			if (nowdist >= max(dist1, dist2)) continue;
			if (dist1 > dist2) {
				y = a[i].second;
				nowdist = dist1;
			} else {
				x = a[i].second;
				nowdist = dist2;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

// hehe ~


