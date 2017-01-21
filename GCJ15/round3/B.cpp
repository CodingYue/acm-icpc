#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int sum[1111];
int diff[1111];

pii A[1111];

bool check(int mid, int n, int K) {
	long long a = 0;
	long long b = 0;
	for (int i = 1; i <= K; ++i) {
		a -= 
	}
}

int main(void) {

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		
		int n, K; scanf("%d %d", &n, &K);
		for (int i = 1; i <= n-K+1; ++i) scanf("%d", &sum[i]);

		for (int i = 1; i <= n-k; ++i) diff[i] = sum[i+1]-sum[i];
		
		for (int i = 1; i <= n-K+1; ++i) {
			int s = 0;
			for (int j = i; j <= n-K; j += K) {
				s += diff[j];
				A[i].first = min(A[i].first, s);
				A[i].second = max(A[i].second, s);
			}
		}
		long long l = 0, r = 1e18;
		if (check(l, n, K)) {
			cout << l << endl;
		} else {
			while (l + 1 < r) {
				long long mid = (l+r) / 2;
				if (check(mid, n, K)) r = mid; else l = mid;
			}
		}
		cout << r << endl;
	}

	return 0;
}
