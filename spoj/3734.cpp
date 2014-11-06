#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int mod = (int) 1e9 + 7;

vector<int> edges[1005];

int h[1005];
int seq[1005];
int fa[1005];
int lowest[5555];
pii range[1005];

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) return;
	fa[a] = b;
	range[b].first = min(range[b].first, range[a].first);
	range[b].second = max(range[b].second, range[a].second);
	lowest[b] = min(lowest[b], lowest[a]);
}
pii block_range[1005];
int len[1005];
int f[1005][555];
int fact[1111111];
int invfact[1111111];
int g[2][1005];

int size[1005];
void add(int &x, int v) {
	x += v;
	if (x >= mod) x -= mod;
}
int C(int n, int K) {
	if (K < 0 || K > n) return 0;
	if (n < 0) return 0;
	return (LL) fact[n] * invfact[K] % mod * invfact[n-K] % mod;
}
void dp(int u) {

	vector<int> seq;
	for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
		seq.push_back(*it);
		dp(*it);
	}
	
	int cursize = 0;
	int now = 0, next = 1;

	memset(g, 0, sizeof g);
	g[now][0] = 1;
	for (int i = 0; i < seq.size(); ++i) {
		int v = seq[i];
	//	memset(g[now], 0, sizeof g[now]);
		memset(g[next], 0, sizeof g[next]);
		for (int j = 0; j <= cursize; ++j) if (g[now][j]) {
			for (int choose = 0; choose <= size[v]; ++choose) {
				add(g[next][choose+j], (LL) g[now][j] * f[v][choose] % mod);
			}
		}
		cursize += size[v];
		swap(next, now);
	}
	//if (cursize > size[u]) while(1);
//	assert(cursize <= size[u]);
	for (int K = 0; K <= size[u]; ++K) {
		f[u][K] = 0;
		for (int j = 0; j <= cursize && j <= K; ++j) {
			add(f[u][K], (LL) g[now][j] * C(size[u]-j, K-j) % mod * C(len[u], K-j) % mod * fact[K-j] % mod);
		}
	}
}
int fpow(int a, int t, int mod) {
	int res = 1;
	for (; t; t >>= 1, a = (LL) a * a % mod)
		if (t & 1) res = (LL) res * a % mod;
	return res;
}
void pre(int n) {
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = (LL) fact[i-1] * i % mod;
	invfact[n] = fpow(fact[n], mod-2, mod);
	for (int i = n - 1; i >= 1; --i) invfact[i] = (LL) invfact[i+1] * (i+1) % mod;
}
bool cover(const pii &a, const pii &b) {
	return a.first <= b.first && b.second <= a.second;
}
int height[1005];
int main() {

	pre(1000000);

	//while(1);

	//freopen("in","r",stdin);

	int n, K; scanf("%d %d", &n, &K);
	for (int i = 0; i < n; ++i) {
		scanf("%d", h + i);
		seq[i] = h[i];
	}
	sort(seq, seq + n);
	int m = unique(seq, seq + n) - seq;


	int tot = 1;
	block_range[0] = pii(0, n-1);
	size[0] = n;
	for (int k = 0; k < m; ++k) {
	
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
			range[i] = pii(i, i);
			lowest[i] = h[i];
		}
		
		for (int i = 0; i < n; ++i) if (h[i] >= seq[k]) {
			if (i > 0 && h[i-1] >= seq[k]) merge(i, i-1);
		}
		
		for (int i = 0; i < n; ++i) if (lowest[i] == seq[k] && get(i) == i) {
			block_range[tot] = range[i];
			height[tot] = seq[k];
			size[tot] = range[i].second - range[i].first + 1;
			for (int x = tot-1; x >= 0; --x) {
				if (!cover(block_range[x], block_range[tot])) continue;

				edges[x].push_back(tot);
				len[tot] = height[tot]-height[x];
				break;
			}
			tot++;
		}
			
//		if (tot > 1000) while(1);
	}
	dp(0);
	printf("%d\n", f[0][K]);

	return 0;
}
