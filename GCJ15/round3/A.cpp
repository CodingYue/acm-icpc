#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

typedef pair<int, int> pii;
#define lowbit(x) (x&-x)

int C[2222222];
int L[1111111];
int R[1111111];
int S[1111111];
int M[1111111];
vector<int> edges[1111111];


void add(int x, int v) {
	for (; x <= 2000005; x +=  lowbit(x)) C[x] += v;
}
int ask(int x) {
	int res = 0;
	for (; x; x -= lowbit(x)) res += C[x];
	return res;
}

void bfs(int s) {
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto &v : edges[u]) {
			L[v] = min(L[u], L[v]);
			R[v] = max(R[u], R[v]);
			que.push(v);
		}
	}
}
pii inter[11111111];

int main(void) {

	int cases; scanf("%d", &cases);

	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);

		int n, D; scanf("%d %d", &n, &D);
		int S0, As, Cs, Rs;
		scanf("%d %d %d %d", &S0, &As, &Cs, &Rs);
		int M0, Am, Cm, Rm;
		scanf("%d %d %d %d", &M0, &Am, &Cm, &Rm);

		memset(C, 0, sizeof C);

		M[0] = M0;
		S[0] = S0;

		for (int i = 1; i < n; ++i) {
			S[i] = ((LL) S[i-1] * As + Cs) % Rs;
			M[i] = ((LL) M[i-1] * Am + Cm) % Rm;
		}
		for (int i = 0; i < n; ++i) {
			edges[i].clear();
			L[i] = R[i] = S[i];
		}

		for (int i = 1; i < n; ++i) {
			edges[M[i] % i].push_back(i);
		}
		bfs(0);
		int m = 0;
		for (int i = 0; i < n; ++i) {
		//	if (L[i] > R[i]) continue;
			inter[m++] = pii(L[i], R[i]);
		}
		sort(inter, inter + m);
		for (int i = 0; i < m; ++i) add(inter[i].second+1, 1);
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			ans = max(ans, ask(inter[i].first + D+1));
			add(inter[i].second+1, -1);
		}
		printf("%d\n", ans);
	}

	return 0;
}
