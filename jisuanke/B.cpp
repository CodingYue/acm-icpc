#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))

const int INF = (int) 1e9+1;

int ufs_f[111111];
vector<pii> edges[111111];
long long dist[111111];
int depth[111111];
int fa[111111][20];
int w[111111];

int get(int x) {
	if (x == ufs_f[x]) return x;
	return ufs_f[x] = get(ufs_f[x]);
}

bool vis[111111];
int que[111111];
int lca(int x,int y) {
	if(depth[x] < depth[y]) swap(x,y);
	int delta = depth[x]-depth[y];
	for(int i = 0;i < 18;i++) if(delta&(1<<i)) x = fa[x][i];
	for(int i = 18-1;i >= 0;i--) if(fa[x][i] != fa[y][i]) { x = fa[x][i]; y = fa[y][i]; }
	if(x != y) x = fa[x][0];
	return x;
}
void pre(int u) {
	for (int i = 1; i < 18; ++i) {
		int p = fa[u][i-1];
		if (p) fa[u][i] = fa[p][i-1];
		else fa[u][i] = 0;
	}
}
void bfs() {
	int front = 0, tail = 0;
	que[0] = 1;
	dist[1] = 0;
	for (; front <= tail; ++front) {
		int u = que[front];
		vis[u] = true;
		pre(u);
		for (auto &v : edges[u]) {
			if (vis[v.first]) continue;
			dist[v.first] = dist[u] + v.second;
			depth[v.first] = depth[u] + 1;
			fa[v.first][0] = u;
			que[++tail] = v.first;
		}
	}
}

long long get_dist(int x, int y) {
	int LCA = lca(x, y);
	return dist[x] + dist[y] - 2*dist[LCA];
}
pii a[111111];
pii who[111111];
void merge(int x, int y) {
	ufs_f[x] = y;
	int here[4] = {who[x].first, who[x].second, who[y].first, who[y].second};
	for (int s = 0; s < (1<<4); ++s) {
		if (__builtin_popcount(s) == 2) {
			int a = -1;
			int b = -1;
			for (int t = 0;t < 4; ++t) if (s >> t & 1){
				if (a == -1) a = here[t];
				else b = here[t];
			}
			if (get_dist(a, b) > get_dist(who[y].first, who[y].second)) {
				who[y].first = a;
				who[y].second = b;
			}
		}
	}
}
int main(void) {


	int cases; scanf("%d", &cases);
	while (cases--) {
		int n = 0; scanf("%d", &n);

		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			ufs_f[i] = i;
			who[i] = pii(i, i);
			vis[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			int x = 0;
			scanf("%d", &x);
			a[i] = pii(x, i);
		}

		for (int i = 1; i < n; ++i) {
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			edges[u].push_back(pii(v, w));
			edges[v].push_back(pii(u, w));
		}
		bfs();
		
		for (int i = 1; i <= n; ++i) vis[i] = false;
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			int x = a[i].second;
			vis[x] = true;
			for (auto &it : edges[x]) {
				int y = it.first;
				if (!vis[y]) continue;
				if (get(x) != get(y)) {
					merge(get(x), get(y));
				}
			}
			x = get(x);
			long long maxdist = get_dist(who[x].first, who[x].second);
			ans = max(ans, (LL) a[i].first * maxdist);
		}
		cout << ans << endl;
	}

	return 0;
}
