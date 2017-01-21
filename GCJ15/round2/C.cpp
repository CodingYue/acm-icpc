#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <iostream>
using namespace std;
 
#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define MP make_pair
#define pb push_back
typedef pair<int,int> PII;
typedef long long LL;
 
const int MaxN = 100005;
const int INF = 10000005;
 
int sink, source, Vn;
int h[MaxN], vh[MaxN];
struct Edge {
    int v, f; Edge *next, *pre;
    Edge(int v, int f, Edge *next)
        : v(v), f(f), next(next) {}
} *g[MaxN];
void addedge(int u, int v, int f) {
    g[u] = new Edge(v, f, g[u]);
    g[v] = new Edge(u, 0, g[v]);
    g[u]->pre = g[v]; g[v]->pre = g[u];
}
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

vector<string> vec[1111];
map<string, int> cnt;

int main(void) {


	int cases; scanf("%d", &cases);

	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		
		int n = 0; scanf("%d ", &n);
		cnt.clear();
		int tot = 0;
	
		for (int i = 0; i < n; ++i) {
			vec[i].clear();
			string s;
			getline(cin, s);
			string tmp = "";
			
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == ' ') {
					vec[i].push_back(tmp);
					tmp = "";
				} else {
					tmp += s[j];
				}
			}
			vec[i].push_back(tmp);
			sort(vec[i].begin(), vec[i].end());
			vec[i].resize(unique(vec[i].begin(), vec[i].end()) - vec[i].begin());
			for (auto v : vec[i]) cnt[v] = ++tot;

			//for (auto &v : vec[i]) cout << v << " ";
			//cout << endl;
		}
		memset(g, 0, sizeof g);
		memset(vh, 0, sizeof vh);
		memset(h, 0, sizeof h);

		source = n;
		sink = source+1;
		addedge(source, 0, 1111111);
		addedge(1, sink, 1111111);
		Vn = n+2;
		vh[0] = Vn;

		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j) {
				int equal = 0;
				for (auto &a : vec[i]) {
					for (auto &b : vec[j]) {
						if (a == b) {
							++equal;
						}
					}
				}
				addedge(i, j, equal);
				addedge(j, i, equal);
			}

		int ans = 0;
		while (h[source] < Vn) ans += sap(source, 1111111);
		printf("%d\n", ans);


	}

	
	return 0;
}
