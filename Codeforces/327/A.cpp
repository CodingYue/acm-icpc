#include <bits/stdc++.h>
using namespace std;

bool fuck[1111111];
int a[1111111];

int main(void) {

	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 2; i < n; ++i) {
		if (a[i] != a[i-1] && a[i] != a[i+1]) {
			fuck[i] = true;
		}
	}

	int ans = 0;
	vector<int> res;

	for (int i = 1; i <= n; ) {
		if (!fuck[i]) {
			res.push_back(a[i]);
			++i;
		}
		else {
			int j = i;
			for (;j <= n && fuck[j]; ++j);
			ans = max(ans, (j-i+1)/2);
			for (int k = i; k < i+(j-i)/2; ++k) res.push_back(a[i-1]);
			for (int k = i+(j-i)/2; k < j; ++k) res.push_back(a[j]);
			i = j;
		}
	}
	printf("%d\n", ans);
	for (auto x : res) printf("%d ", x);

	return 0;
}