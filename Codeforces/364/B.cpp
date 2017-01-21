#include <bits/stdc++.h>
using namespace std;

long long  ans;
int n, k;
int f[1111111];
int cnt[1111111];
vector<int> edges[222222];

void dfs(int u, int fa) {
	f[u] = cnt[u];
	for (auto v : edges[u]) {
		if (v != fa) {
			dfs(v, u);
			int left = 2*k - cnt[v];
			if (f[v] > left) {
				int p = f[v] - left;
				f[v] -= 2 * ((p+1) / 2);
			}
			ans += f[v];
			f[u] += f[v];
			cnt[u] += cnt[v];
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2*k; ++i) {
		int x; scanf("%d", &x);
		cnt[x] = 1;
	}
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	ans = 0;
	dfs(1, 0);
	cout << ans << endl;


	return 0;
}