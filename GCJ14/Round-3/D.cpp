// File Name: D.cpp
// Author: YangYue
// Created Time: Sat Jun 14 23:49:27 2014
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

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int f[81][81][81][81];
int v[81];
int pre[81];
bool vis[81][81][81][81];
bool in[81][81][81];
vector<int> edges[81];

int dp(int sx, int sy, int i, int j) {
	int &res = f[sx][sy][i][j];
	if (vis[sx][sy][i][j]) {
		return res;
	}
	vis[sx][sy][i][j] = 1;
	res = 0;
	int tmp = -INF;
	bool can1 = 0;
	for (vector<int> :: iterator it = edges[i].begin(); it != edges[i].end(); ++it) {
		int k = *it;
		if (in[k][sx][i] || in[k][sy][j]) continue;
		tmp = max(tmp, v[k] - dp(sy, sx, j, k));
		can1 = 1;
	}
	bool can2 = 0;
	for (vector<int> :: iterator it = edges[j].begin(); it != edges[j].end(); ++it) {
		int k = *it;
		if (in[k][sx][i] || in[k][sy][j]) continue;
		can2 = 1;
	}
	if (!can1 && !can2) {
		return res;
	}
	if (!can1) tmp = max(tmp, -dp(sy, sx, j, i));
	return res = tmp;
}
void dfs(int i) {
	for (vector<int> :: iterator it = edges[i].begin(); it != edges[i].end(); ++it) {
		if (pre[i] == *it) continue;
		pre[*it] = i;
		dfs(*it);
	}
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		printf("Case #%d: ", cas);
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i) edges[i].clear();
		for (int i = 1; i <= n; ++i) scanf("%d", v + i);
		for (int i = 1; i < n; ++i) {
			int x; scanf("%d", &x);
			edges[i].push_back(x);
			edges[x].push_back(i);
		}
		memset(in, 0, sizeof in);
		for (int i = 1; i <= n; ++i) {
			pre[i] = -1;
			dfs(i);
			for (int x = 1; x <= n; ++x) {
				for (int j = x; j != -1; j = pre[j]) in[j][i][x] = 1;
			}
		}
		memset(vis, 0, sizeof vis);
		int best = -INF;
		for (int x = 1; x <= n; ++x) {
			int tmp = INF;
			for (int y = 1; y <= n; ++y) if (x != y) {
				tmp = min(tmp, dp(x, y, x, y) - v[y] + v[x]);
			}
			tmp = min(tmp, dp(x, x, x, x));
			best = max(best, tmp);
		}
		printf("%d\n", best);
	}
	
	return 0;
}

// hehe ~


