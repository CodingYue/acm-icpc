// File Name: D.cpp
// Author: YangYue
// Created Time: Mon Apr 14 18:36:26 2014
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

const int MaxN = 10005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;


int n, m;
int et = 0;
int source, sink, Vn;
struct Edge {
	int v, f;
	Edge *next, *pre;
	Edge(){}
	Edge(int v, int f, Edge *next, Edge *pre) :
		v(v), f(f), next(next), pre(pre) {}
} *g[MaxN], edge[MaxN * 20];
void ins(int u, int v, int f) {
	edge[et] = Edge(v, f, g[u], &edge[et+1]);
	edge[et+1] = Edge(u, 0, g[v], &edge[et]);
	g[u] = &edge[et++];
	g[v] = &edge[et++];
}
struct OriEdge {
	int v, w, c;
	OriEdge *next;
	OriEdge(){}
	OriEdge(int v, int w, int c, OriEdge *next)
		: v(v), w(w), c(c), next(next) {}
} oriedge[MaxN * 10], *org[MaxN * 10];
int h[MaxN], vh[MaxN];
int sap(int u, int flow) {
	if (u == sink) return flow;
	int tmp = Vn - 1, f = 0;
	for (Edge *p = g[u]; p; p = p->next) {
		if (p->f && h[u] == h[p->v] + 1) {
			int tmpf = sap(p->v, min(flow - f, p->f));
			p->f -= tmpf, p->pre->f += tmpf, f += tmpf;
			if (h[source] == Vn || f == flow) return f;
		}
		if (p->f) tmp = min(tmp, h[p->v]);
	}
	if (!f) {
		--vh[h[u]];
		if (!vh[h[u]]) h[source] = Vn;
		else vh[h[u] = tmp + 1]++;
	}
	return f;
}
void addedge(int u, int v, int w, int c) {
	oriedge[et] = OriEdge(v, w, c, org[u]);
	org[u] = &oriedge[et++];
}
int que[MaxN* 100];
bool inque[MaxN];
void spfa(int source, int *dist) {
	for (int i = 1; i <= n; ++i) dist[i] = INF; dist[source] = 0;
	int front, tail; que[front = tail = 0] = source;
	memset(inque, 0, sizeof inque); inque[source] = 1;
	for (; front <= tail; ++front) {
		int u = que[front];
		for (OriEdge *p = org[u]; p; p = p->next) if (dist[u] + p->w < dist[p->v]) {
			dist[p->v] = dist[u] + p->w;
			if (!inque[p->v]) {
				inque[p->v] = 1;
				que[++tail] = p->v;
			}
		}
		inque[u] = 0;
	}
}
int dist[2][MaxN];
int main()
{
	//freopen("in","r",stdin);

	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		et = 0;
		memset(g, 0, sizeof g);
		memset(org, 0, sizeof org);
		memset(h, 0, sizeof h);
		memset(vh, 0, sizeof vh);
		scanf("%d %d", &source, &sink);
		for (int i = 0; i < m; ++i) {
			int u, v, w, c; scanf("%d %d %d %d", &u, &v, &w, &c);
			addedge(u, v, w, c);
			addedge(v, u, w, c);
		}
		et = 0;
		spfa(source, dist[0]);
		spfa(sink, dist[1]);
		for (int u = 1; u <= n; ++u) 
			for (OriEdge *p = org[u]; p; p = p->next) {
				if (dist[0][u] + p->w + dist[1][p->v] == dist[0][sink]) {
					ins(u, p->v, p->c);
				}
			}
		Vn = n;
		vh[0] = Vn;
		int ans = 0;
		while (h[source] < Vn) ans += sap(source, INF);
		printf("%d\n", ans);
	}

	return 0;
}

// hehe ~


