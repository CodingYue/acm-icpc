#include <bits/stdc++.h>
using namespace std;


int main(void) {

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {

		printf("Case #%d: ", ++cas);

		int R, C; scanf("%d %d", &R, &C);
		int n = 0; scanf("%d", &n);
		
		int cnt = 0;
		for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if ((i+j)&1) {
				++cnt;
			}
		}
		if (cnt >= n) {
			puts("0");
			continue;
		}
		n -= cnt;
		vector<int> seq;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) {
				if ((i+j)&1) continue;
				int pos = 0;
				if (i) ++pos;
				if (j) ++pos;
				if (i+1 < R) ++pos;
				if (j+1 < C) ++pos;
				seq.push_back(pos);
			}
		sort(seq.begin(), seq.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) ans += seq[i];

		n += cnt;
		cnt = 0;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) {
				if ((i+j)&1) continue;
				++cnt;
			}
		if (cnt >= n) {
			puts("0");
			continue;
		}
		n -= cnt;
		seq.clear();
		for (int i = 0; i < R; ++i)
			for (int j = 0 ; j < C; ++j) {
				if (!((i+j)&1)) continue;
				int pos = 0;
				if (i) ++pos;
				if (j) ++pos;
				if (i+1 < R) ++pos;
				if (j+1 < C) ++pos;
				seq.push_back(pos);
			}
		int sum = 0;
		for (int i = 0; i < n; ++i) sum += seq[i];
		ans = min(ans, sum);
		printf("%d\n", ans);
	}

	return 0;
}

