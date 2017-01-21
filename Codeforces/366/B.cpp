#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 32222;
const int INF = 111111111;
const int MAXM = 333333;
struct EDGE {
	int cost, cap, v;
	int next, re;
}edge[MAXM];
int head[MAXN], e;
int vis[MAXN];
int ans, cost, src, des, N;
void init() {
	memset(head, -1, sizeof(head));
	e = ans = cost = 0;
}
void addedge(int u, int v, int cap, int cost) {
	edge[e].v = v; edge[e].cap = cap;
	edge[e].cost = cost; edge[e].re = e + 1;
	edge[e].next = head[u]; head[u] = e++;

	edge[e].v = u; edge[e].cap = 0;
	edge[e].cost = -cost; edge[e].re = e - 1;
	edge[e].next = head[v]; head[v] = e++;
}
int aug(int u, int f) {
	if(u == des) {
		ans += cost * f;
		return f;
	}
	vis[u] = 1;
	int tmp = f;
	for(int i = head[u]; i != -1; i = edge[i].next) {
		if(edge[i].cap && !edge[i].cost && !vis[edge[i].v]) {
			int delta = aug(edge[i].v, tmp < edge[i].cap ? tmp : edge[i].cap);
			edge[i].cap -= delta; edge[edge[i].re].cap += delta;
			tmp -= delta;
			if(!tmp) return f;
		}
	}
	return f - tmp;
}
bool modlabel() {
	int delta = INF;
	for(int u = 0; u < N; u++) if(vis[u])
		for(int i = head[u]; i != -1; i = edge[i].next)
			if(edge[i].cap && !vis[edge[i].v] && edge[i].cost < delta) delta = edge[i].cost;
	if(delta == INF) return false;
	for(int u = 0; u < N; u++) if(vis[u])
		for(int i = head[u]; i != -1; i = edge[i].next)
			edge[i].cost -= delta, edge[edge[i].re].cost += delta;
	cost += delta;
	return true;
}
void costflow() {
	do do memset(vis, 0, sizeof(vis)); 
	while(aug(src, INF)); while(modlabel());
}

int x[11111];
int a[11111];
int b[11111];
int c[11111];
int d[11111];

int left_out[11111];
int left_in[11111];
int right_out[11111];
int right_in[11111];
int src2i[11111];
int i2des[11111];

int main(void) {

	int n, s, e;
	scanf("%d %d %d", &n, &s, &e);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);

	int total = 0;
	src = total++;
	des = total++;

	init();

	for (int i = 1; i <= n; ++i) {
		left_in[i] = total++;
		left_out[i] = total++;
		right_in[i] = total++;
		right_out[i] = total++;
		if (i != s && i != e) {
			src2i[i] = total++;
			i2des[i] = total++;
		} else if (i == s) {
			src2i[i] = total++;
			i2des[i] = -1;
		} else if (i == e) {
			src2i[i] = -1;
			i2des[i] = total++;
		}
	}
	for (int i = 1; i <= n; ++i) {

		if (src2i[i] != -1) {
			addedge(src, src2i[i], 1, 0);
			addedge(src2i[i], left_out[i], 1, c[i]);
			addedge(src2i[i], right_out[i], 1, d[i]);
		}
		if (i2des[i] != -1) {
			addedge(i2des[i], des, 1, 0);
			addedge(left_in[i], i2des[i], 1, a[i]);
			addedge(right_in[i], i2des[i], 1, b[i]);
		}
		if (i > 1) {
			addedge(right_in[i], right_in[i-1], INF, x[i] - x[i-1]);
			addedge(left_out[i], right_in[i-1], INF, x[i] - x[i-1]);
		}
		if (i < n) {
			addedge(left_in[i], left_in[i+1], INF, x[i+1] - x[i]);
			addedge(right_out[i], left_in[i+1], INF, x[i+1] - x[i]);
		}
	}
	N = total;
	costflow();
	cout << ans << endl;

	return 0;
}