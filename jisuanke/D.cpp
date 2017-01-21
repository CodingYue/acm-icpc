#include <bits/stdc++.h>
using namespace std;

struct FUCK{ 
	int s, w, c;
	FUCK(){}
	FUCK(int s, int w, int c) : s(s), w(w), c(c) {}
	bool operator < (const FUCK &b) const {
		return s < b.s;
	}
} A[111];

pair<int, long long> C[1111111], val[11111110];

int main(void) {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &A[i].s, &A[i].w, &A[i].c);
		}
		sort(A + 1, A + n + 1);
		long long ans = 1e18;
		for (int i = 1; i <= n; ++i) {
			int c1 = 0;
			int c2 = 0;
			for (int j = 1; j < i; ++j) if (A[j].s < A[i].s) ++c1;
			for (int j = i+1; j <= n; ++j) if (A[j].s > A[i].s) ++c2;
			if (c1 <= c2) {
				int tot = 0;
				for (int p1 = 1; p1 <= c1; ++p1)
					for (int p2 = p1+1; p2 <= c1; ++p2) {
						if (A[p2].s == A[p1].s) continue;
						for (int p3 = p2+1; p3 <= c1; ++p3) if (A[p3].s != A[p2].s) {
							long long tmp = A[p1].w + A[p2].w + A[p3].w;
							if (tmp + A[i].w < m) val[++tot] = make_pair(tmp, (long long) A[p1].c + A[p2].c + A[p3].c);
						}
					}
				sort(val, val + tot + 1);
				int c = 0;
				for (int j = 1; j <= tot; ++j) if (!c || val[j].second < C[c].second) {
					C[++c] = val[j];
				}
				if (!c) continue;
				C[++c] = make_pair(m+1, m+1);
				for (int p1 = n-c2+1; p1 <= n; ++p1)
					for (int p2 = p1+1; p2 <= n; ++p2) {
						if (A[p2].s != A[p1].s) {
							for (int p3 = p2+1; p3 <= n; ++p3) if (A[p3].s != A[p2].s) {
								long long t = A[p1].w + A[p2].w + A[p3].w;
								if (t + A[i].w < m) {
									int rem = m - t - A[i].w;
									int ps = upper_bound(C + 1, C + c + 1, make_pair(rem, 1LL << 60)) - C;
									--ps;
									if (ps > 0) ans = min(ans, C[ps].second + A[p1].c + A[p2].c + A[p3].c + A[i].c);
									if (ps > 0) ans = min(ans, C[ps].second + A[p1].c + A[p2].c + A[p3].c + A[i].c);
								}
							}
						}
					}
			}
						else {
							for (int p1 = 1; p1 <= c1; ++p1)
								for (int p2 = p1+1; p2 <= c1; ++p2) {
									if (A[p2].s == A[p1].s) continue;
									for (int p3 = p2+1; p3 <= c1; ++p3) if (A[p3].s != A[p2].s) {
										long long tmp = A[p1].w + A[p2].w + A[p3].w;
										if (tmp + A[i].w < m) val[++tot] = make_pair(tmp, (long long) A[p1].c + A[p2].c + A[p3].c);
									}
								}
							
						}
			
		}
		if (ans > 1e17) puts("-1"); else cout << ans << endl;
	}
	return 0;
}
