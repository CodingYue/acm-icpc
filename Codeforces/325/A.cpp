#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int v[4444];
int d[4444];
int p[4444];

int main(void) {

	int n = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &v[i], &d[i], &p[i]);
	}

	LL sumd = 0;

	vector<int> ans;

	for (int i = 1; i <= n; ++i) {
		if (p[i] - sumd < 0) {
			sumd += d[i];
			continue;
		} else {
			ans.push_back(i);
			int nowv = v[i];
			LL nowd = sumd;
			for (int j = i+1; j <= n; ++j) {
				if (p[j] - nowd < 0) {
					nowd += d[j];
					continue;
				}
				p[j] -= nowv;
				if (p[j] - nowd < 0) {
					nowd += d[j];
				}
				--nowv;
				if (nowv <= 0) break;
			}
		}

	}

	printf("%u\n", ans.size());
	for (auto x : ans) printf("%d ", x);

	return 0;
}
