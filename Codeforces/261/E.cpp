// File Name: E.cpp
// Author: YangYue
// Created Time: Sat Aug 16 00:10:43 2014
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

const int MaxN = 3000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n, m;
int f[MaxN], tmpf[MaxN];
struct Edge {
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const Edge &b) const {
		return w < b.w;
	}
} edge[MaxN];
int main()
{
	freopen("in","r",stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		edge[i] = Edge(u, v, x);
	}
	sort(edge, edge + m);
	set<int> SET;
	for (int i = 0; i < m; ) {
		int j;
		set<int> myset;
		for (j = i; j < m && edge[i].w == edge[j].w; ++j) {
			int u = edge[j].u;
			int v = edge[j].v;
			myset.insert(u);
			myset.insert(v);
		}
		for (auto x : myset) tmpf[x] = f[x];
		for (j = i; j < m && edge[i].w == edge[j].w; ++j) {
			int u = edge[j].u;
			int v = edge[j].v;
			tmpf[v] = max(tmpf[v], f[u] + 1);
		}
		for (auto x : myset) f[x] = tmpf[x];
		i = j;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
	printf("%d\n", ans);
	printf("%d\n", (1<<31)-1);
	
	return 0;
}

// hehe ~


