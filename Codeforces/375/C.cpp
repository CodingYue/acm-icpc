#include <bits/stdc++.h>
using namespace std;

int a[2222];
set<int> SET[2222];
set<int> other;

int main(void) {

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] <= m) {
			SET[a[i]].insert(i);
		} else {
			other.insert(i);
		}
	}

	int limit = n/m;
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		while (SET[i].size() > limit) {
			other.insert(*SET[i].begin());
			SET[i].erase(SET[i].begin());
		}
	}

	for (int i = 1; i <= m; ++i) {
		while (SET[i].size() < limit) {
			SET[i].insert(*other.begin());
			++ans;
			other.erase(other.begin());
		}
	}

	for (int i = 1; i <= m; ++i) {
		while (SET[i].size()) {
			int x = *SET[i].begin();
			a[x] = i;
			SET[i].erase(x);
		}
	}
	printf("%d %d\n", limit, ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}