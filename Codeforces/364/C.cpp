#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

const int MAXN = 1111;
const int MAXM = 33333;

vector<int> marked;
int s, t;
int x[33333], y[33333], w[33333];
bool vis[1111];
vector<int> edges[1111];

int DFN[MAXN],Low[MAXN];
bool isBridge[MAXM];
int idx = 0;


int et = 0;
struct EDGE {
	int y;
	int eid;
	EDGE(){}
	EDGE(int y, int eid) : y(y), eid(eid) {}
} edge[111111], *E[1111];

void addedge(int u, int v, int eid) {
	edge[et] = EDGE(v, eid)
	E[u] = &edge[et++];
}

int tarjan(int x,int peid=-1) {
	vis[x] = true;
	DFN[x] = Low[x] = ++idx;
	for(EDGE* e = E[x];e;e = e->Next) {
		int y = e->y; int eid = e->id;
		if(eid == peid) continue;
		if(!vis[y]) {
			tarjan(y,eid);
			Low[x] = min(Low[x],Low[y]);
		}
		else Low[x] = min(Low[x],DFN[y]);
	}
	if(peid != -1 && Low[x] == DFN[x]) isBridge[peid] = true;
	return 0;
}


long long calcIfDelete(int del, int n, int m) {
	long long res = 0;
	if (del != -1) res += w[del];
	et = 0;
	memset(E, 0, sizeof E);
	for (int i = 0; i < m; ++i) {
		if (del == i) continue;
		int a = x[i];
		int b = y[i];
		addedge(a, b, i);
		addedge(b, a, i);		
	}
	memset(DFN, 0, sizeof DFN);
	memset(Low, 0, sizeof Low);
	memset(isBridge, 0, sizeof isBridge);
	memset(vis, 0, sizeof vis);
	idx = 0;
	for (int i = 0; i < n; ++i) if (!DFN[i]) {
		tarjan(i, -1);
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 0; i < m; ++i) {
		if (i == del) continue;
		if (isBridge[i]) continue;
		fa[x[i]] = get(y[i]);
	}
	if (get(s) == get(t)) return 1111111111111ll;
	for (int i = 0; i < m; ++i) {
		
	}
}

int main(void) {

	int n, m; scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		edges[x].push_back(i);
		edges[y].push_back(i+n);
		EDGE[i] = piiii(pii(x, y), pii(w, i));
	}
	queue<int> que;
	vis[s] = true;
	que.push(s);

	while (!que.empty()) {
		int u = que.front();
		for (auto idx : edges[u]) {
			int v;
			if (idx > n) {
				idx -= n;
				v = EDGE[idx].first.first;
			} else {
				v = EDGE[idx].first.second;
			}
			vis[v] = true;
			marked.push_back(idx);
			que.push(v);
		}
	}

	long long ans = 1111111111111ll;
	marked.push_back(-1);
	for (auto x : marked) {
		ans = min(ans, calcIfDelete(x, n, m));
	}

	return 0;
}