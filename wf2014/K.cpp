// File Name: K.cpp
// Author: YangYue
// Created Time: Thu Jun 26 09:55:28 2014
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

int n, m;
PII C[MaxN];
PII interval[MaxN];
PII Tree[MaxN * 4];
int pre[MaxN][22];
int depth[MaxN];
vector<int> edges[MaxN];
void build(int p, int l, int r) {
	Tree[p] = MP(0, 0);
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(p, l, mid);
	build(p, mid + 1, r);
}
PII ask(int p, int l, int r, int i, int j) {
	if (i <= l && j >= r) {
		return Tree[p];
	}
	int mid = (l + r) >> 1;
	PII res = MP(0, 0);
	if (i <= mid) res = max(res, ask(lch(p), l, mid, i, j));
	if (j > mid) res = max(res, ask(rch(p), mid + 1, r, i, j));
	return res;
}
void modify(int p, int l, int r, int x, PII v) {
	if (l == r) {
		Tree[p] = max(Tree[p], v);
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lch(p), l, mid, x, v);
	else modify(rch(p), mid + 1, r, x, v);
	Tree[p] = max(Tree[p], max(Tree[lch(p)], Tree[rch(p)]));
}
int que[MaxN];
void bfs(int s) {
	int front, tail;
	que[front = tail = 0] = s;
	for (; front <= tail; ++front) {
		int u = que[front];
		for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
			if (*it == pre[u][0]) continue;
			depth[*it] = depth[u] + 1;
			que[++tail] = *it;
		}
	}
	for (int j = 1; j <= 20; ++j)
	for (int k = tail; k > 0; --k) {
		int i = que[k];
		if (pre[i][j-1] == -1) continue;
		pre[i][j] = pre[pre[i][j-1]][j-1];
	}
}
int dist(int u, int v) {
	return interval[u].second - interval[v].first + 1;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		if (a > b) b += n;
		interval[i] = MP(a, b);
	}
	
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		modify(1, 1, n, interval[i].first, MP(interval[i].second, i));
	}

	memset(pre, -1, sizeof pre);
	for (int i = 1; i <= m; ++i) {
		PII res = ask(1, 1, n, interval[i].first, interval[i].second + 1);
		if (res.second != 0 && res.first > interval[i].second) {
			pre[i][0] = res.second;
			edges[res.second].push_back(i);
		}
	}
	
	int res = INF;
	for (int i = 1; i <= m; ++i) if (pre[i][0] == -1) bfs(i);
	for (int i = 1; i <= m; ++i) {
		int u = i;
		int target = -1;
		for (int j = 20; j >= 0; --j) {
			int v = pre[u][j];
			if (v == -1) continue;
			if (dist(v, i) < n) {
				u = v;
			} else target = v;
		}
		if (target != -1) {
			res = min(res, depth[i] - depth[target] + 1);
		}
		if (dist(i, i) >= n) res = 1;
	}

	if (res > 10000000) puts("impossible"); 
	else printf("%d\n", res);
	
	return 0;
}

// hehe ~


