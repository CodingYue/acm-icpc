// File Name: D.cpp
// Author: YangYue
// Created Time: Mon Sep 29 00:00:07 2014
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

const int MaxN = 4000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int A[2333][2333];
int fa[2333];
LL dis[2333][2333];
vector<int> edges[2333];
void dfs(int u, int s, int pre) {
	for (auto v : edges[u]) {
		if (v == pre) continue;
		dis[s][v] = dis[s][u] + A[u][v];
		dfs(v, s, u);
	}
}
struct Edge {
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const Edge &b) const {
		return w < b.w;
	}
}edge[MaxN];
int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	int m = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) scanf("%d", &A[i][j]);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (A[i][j] != A[j][i]) {
				puts("NO");
				return 0;
			}
			if (i != j && A[i][j] == 0) {
				puts("NO");
				return 0;
			}
			if (i == j && A[i][j] != 0) {
				puts("NO");
				return 0;
			}
		}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j) edge[m++] = Edge(i, j, A[i][j]);
	sort(edge, edge + m);
	for (int i = 0; i < m; ++i) {
		int u = edge[i].u;
		int v = edge[i].v;
		int a = get(u);
		int b = get(v);
		if (a == b) continue;
		fa[b] = a;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) dfs(i, i, -1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (dis[i][j] != A[i][j]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	
	return 0;
}

// hehe ~


