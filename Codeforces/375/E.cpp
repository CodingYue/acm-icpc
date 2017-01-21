#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m;
vector<pii> EDGE[111111];
vector<pii> edges[1111];
int deg[222];

int main(void) {


	int cases; scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d", &n, &m);
		memset(deg, 0, sizeof deg);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			deg[u]++; deg[v]++;
			EDGE[i].push_back(pii(u, v));
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for (int i = 0; i < m; ++i) {
			int u, v; 
			&u = EDGE[i].first;
			&v = EDGE[i].second;
			if (deg[u] % 2 == 0 && deg[v] % 2 == 0) {
				valid[i] = true;
			} else {
				
			}
		}
	}

	return 0;
}