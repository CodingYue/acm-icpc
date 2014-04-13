#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = (int) 1e9 + 7;

int fpow(int a, int t, int mod) {
	int res = 1;
	for (; t; t >>= 1, a = (long long) a * a % mod)
		if (t & 1) res = (long long) res * a % mod;
	return res;
}
int f[2222222];
int main() {

	//freopen("Iin","r",stdin);
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < m; ++i) {
		int k; scanf("%d", &k);
		int now = 0;
		for (int j = 0; j < k; ++j) {
			int x; scanf("%d", &x); --x;
			now = now + (1 << x);
		}
		f[now]++;
	}
	for (int k = 0; k < n; ++k)
    for (int i = 1; i < 1 << n; ++i)
    {
        if ((i >> k) & 1)
            f[i] += f[i^(1 << k)];
    }

	int res = 0;
	for (int s = 0; s < (1 << n); ++s) {
		int cnt = n - __builtin_popcount(s);
		int c = (cnt % 2 == 1 ? -1 : 1);
		res = ((res + fpow(f[s], p, MOD) * c) % MOD + MOD) % MOD;
	}
	printf("%d\n", res);

	return 0;
