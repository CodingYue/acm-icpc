// File Name: C.cpp
// Author: YangYue
// Created Time: Sat May 31 23:43:28 2014
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


int W, H, B;
int et;
bool yes[105][505];
int num(int i, int j) {
	return j * W + i;
}
int n, m, sink, source, Vn;
int h[MaxN], vh[MaxN];

struct Edge {
    int v, f; 
	Edge *next, *pre;
	Edge(){}
    Edge(int v, int f, Edge *next, Edge *pre)
        : v(v), f(f), next(next), pre(pre) {}
} *g[500000], edge[5000005];
void addedge(int u, int v, int f = 1) {
	edge[et] = Edge(v, f, g[u], &edge[et+1]);
	edge[et+1] = Edge(u, 0, g[v], &edge[et]);
	g[u] = &edge[et++];
	g[v] = &edge[et++];
}
int sap(int u, int flow) {
    if (u == sink) return flow;
    int tmp = Vn - 1, f = 0;
    for (Edge *p = g[u]; p; p = p->next) {
        if (p->f && h[u] == h[p->v] + 1) {
            int tmpf = sap(p->v, std::min(flow - f, p->f));
            p->f -= tmpf, p->pre->f += tmpf, f += tmpf;
            if (h[source] == Vn || f == flow) return f;
        }
        if (p->f) tmp = std::min(tmp, h[p->v]);
    }
    if (!f) {
        --vh[h[u]];
        if (!vh[h[u]]) h[source] = Vn;
        else vh[h[u] = tmp + 1]++;
    }
    return f;
}
int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {

		et = 0;
		memset(h, 0, sizeof h);
		memset(vh, 0, sizeof vh);
		memset(g, 0, sizeof g);

		printf("Case #%d: ", cas);
		scanf("%d %d %d", &W, &H, &B);
		memset(yes, 1, sizeof yes);
		for (int i = 0; i < B; ++i) {
			int x0, y0, x1, y1;
			scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
			for (int x = x0; x <= x1; ++x)
			for (int y = y0; y <= y1; ++y) yes[x][y] = 0;
		}
		int tot = W * H;
		source = 2 * tot;
		sink = 2 * tot + 1;
		for (int i = 0; i < W; ++i)
		for (int j = 0; j < H; ++j) if (yes[i][j]) {
			addedge(num(i, j), num(i, j) + tot);
			int u = num(i, j) + tot;
			if (i + 1 < W) addedge(u, num(i + 1, j));
			if (i) addedge(u, num(i - 1, j));
			if (j + 1 < H) addedge(u, num(i, j + 1));
			if (j) addedge(u, num(i, j - 1));
			if (j == 0) addedge(source, num(i, j));
			if (j == H - 1) addedge(u, sink);
		}
		Vn = 2 * tot + 2;
		vh[0] = Vn;
		int res = 0;
		while (h[source] < Vn) res += sap(source, INF);
		printf("%d\n", res);
	}
	
	return 0;
}

// hehe ~


