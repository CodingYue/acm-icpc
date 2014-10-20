// File Name: F.cpp
// Author: YangYue
// Created Time: Sun Oct 12 20:36:46 2014
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
const int mod = (int) 1e9+7;

PII range[MaxN];
vector<int> edges[MaxN];
vector<int> divisors[MaxN];
int fa[MaxN];
int tmp_f[55][55555];
int f_down[55][55555];
int f_up[55][55555];
int suffix_prod[55][55555];
int prffix_prod[55][55555];
int sons[55555];
int miu[55555];
void add(int &x, int v) {
	if (v < 0) v += mod;
	x = (x + v) % mod;
}
void mul(int &x, int v) {
	if (v < 0) v += mod;
	x = (LL) x * v % mod;
}
void dfs_from_botton(int u) {
	int sons_cnt = 0;
	for (auto &v : edges[u]) {
		if (fa[u] == v) continue;
		fa[v] = u;
		dfs_from_botton(v);
	}
	for (auto &v : edges[u]) {
		if (fa[u] == v) continue;
		sons[++sons_cnt] = v;
		static int f[55555];
		memset(f, 0, sizeof f);
		memset(tmp_f[sons_cnt], 0, sizeof tmp_f[sons_cnt]);
		for (int d = 1; d <= 50000; ++d)
			for (int x = d; x <= 50000; x += d) {
				add(f[d], f_down[v][x]);
			}
		for (int x = range[u].first; x <= range[u].second; ++x)
			for (auto &d : divisors[x]) add(tmp_f[sons_cnt][x], f[d] * miu[d]);
	}
	for (int x = 1; x <= 50000; ++x) prffix_prod[0][x] = suffix_prod[sons_cnt+1][x] = 1;
	for (int i = 1; i <= sons_cnt; ++i)
		for (int x = 1; x <= 50000; ++x) {
			int cur = i > 1 ? prffix_prod[i-1][x] : 1;
			prffix_prod[i][x] = (LL) cur * tmp_f[i][x] % mod;
		}
	for (int x = range[u].first; x <= range[u].second; ++x) f_down[u][x] = prffix_prod[sons_cnt][x];
}
void dfs_from_top(int u) {
	int sons_cnt = 0;
	for (auto &v : edges[u]) {
		if (fa[u] == v) continue;
		sons[++sons_cnt] = v;
		static int f[55555];
		memset(f, 0, sizeof f);
		memset(tmp_f[sons_cnt], 0, sizeof tmp_f[sons_cnt]);
		for (int d = 1; d <= 50000; ++d)
			for (int x = d; x <= 50000; x += d) {
				add(f[d], f_down[v][x]);
			}
		for (int x = range[u].first; x <= range[u].second; ++x)
			for (auto &d : divisors[x]) add(tmp_f[sons_cnt][x], f[d] * miu[d]);
	}
	for (int x = 1; x <= 50000; ++x) prffix_prod[0][x] = suffix_prod[sons_cnt+1][x] = 1;
	for (int i = 1; i <= sons_cnt; ++i)
		for (int x = 1; x <= 50000; ++x) {
			int cur = i > 1 ? prffix_prod[i-1][x] : 1;
			prffix_prod[i][x] = (LL) cur * tmp_f[i][x] % mod;
		}
	for (int i = sons_cnt; i >= 1; --i)
		for (int x = 1; x <= 50000; ++x) {
			int cur = i < sons_cnt ? suffix_prod[i+1][x] : 1;
			suffix_prod[i][x] = (LL) cur * tmp_f[i][x] % mod;
		}

	for (int idx = 1; idx <= sons_cnt; ++idx) {
		int v = sons[idx];
		static int f[55555];
		memset(f, 0, sizeof f);
		for (int d = 1; d <= 50000; ++d)
			for (int x = d; x <= 50000; x += d) {
				add(f[d], (LL) f_up[u][x] * prffix_prod[idx-1][x] % mod * suffix_prod[idx+1][x] % mod);
			}
		for (int x = range[v].first; x <= range[v].second; ++x) {
			int tmp = 0;
			for (auto &d : divisors[x]) {
				add(tmp, f[d] * miu[d]);
			}
			f_up[v][x] = tmp;
		}
	}
	for (auto &v : edges[u]) {
		if (fa[u] == v) continue;
		dfs_from_top(v);
	}
}
bool flag[55555];
int main()
{
	//:w
	//freopen("in","r",stdin);

	miu[1] = 1;
	for (int i = 2; i <= 50000; ++i) if (!flag[i]) 
		for (int j = i; j <= 50000; j += i) {
			if (j/i % i == 0) miu[j] = 0;
			else miu[j] = miu[j/i] * -1;
			if (j > i) flag[j] = true;
		}
	for (int i = 1; i <= 50000; ++i)
		for (int j = i; j <= 50000; j += i) divisors[j].push_back(i);

	int cases; scanf("%d", &cases);
	while (cases--) {
		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			scanf("%d", &range[i].first);
		}
		for (int i = 1; i <= n; ++i) scanf("%d", &range[i].second);
		for (int i = 1; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		memset(f_down, 0, sizeof f_down);
		memset(f_up, 0, sizeof f_up);
		dfs_from_botton(1);
		for (int x = range[1].first; x <= range[1].second; ++x) f_up[1][x] = 1;
		dfs_from_top(1);
		for (int i = 1; i <= n; ++i) {
			int ans = 0;
			for (int x = range[i].first; x <= range[i].second; ++x)
				add(ans, (LL) x * f_down[i][x] % mod * f_up[i][x] % mod);
			printf("%d%c", ans, i == n ? '\n' : ' ');
		}
	}
	
	return 0;
}

// hehe ~


