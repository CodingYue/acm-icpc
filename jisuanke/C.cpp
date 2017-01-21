#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))

const int INF = (int) 1e9+1;

int f[15][3][205][8];

int bit_A[3][111];
int bit_R[3][111];
int bit_n[111];

int C[1111][1111];
int dp(int i, int pos, int remain, int mask) {
	if (i == 0) {
		return 1;
	}
	if (pos == 0) {
		remain = remain * 47 + bit_n[i];
	}
	if (remain >= 200) remain = 200;
	if (f[i][pos][remain][mask] != -1) {
		return f[i][pos][remain][mask];
	}
	int &res = f[i][pos][remain][mask];
	res = 0;
	int range = 0;

	if (mask >> pos & 1) {
		range = 46;
	} else {
		range = bit_R[pos][i];
	}


	for (int x = 0; x <= range; ++x) {
		if (x > remain) break;
		if (pos == 2) {
			int next = remain-x;
			res += C[bit_A[pos][i]][x] * dp(i-1, 0, next, mask | ((x < range) << pos));
		} else {
			int next = remain-x;
			res += C[bit_A[pos][i]][x] * dp(i, pos+1, next, mask | ((x<range)<<pos));
		}
	}

	return res % 47;
}


int get_ans(LL n, LL *range, LL *a) {
	long long maxlen = 0;
	for (int i = 0; i < 3; ++i) {
		memset(bit_A[i], 0, sizeof bit_A[i]);
		memset(bit_R[i], 0, sizeof bit_R[i]);
		for (long long t = range[i], len = 0; t; t /= 47) bit_R[i][++len] = t % 47, maxlen = max(maxlen, len);
		for (long long t = a[i], len = 0; t; t /= 47) bit_A[i][++len] = t % 47, maxlen = max(maxlen, len);
	}

	memset(bit_n, 0, sizeof bit_n);
	for (long long t = n, len = 0; t; t /= 47) bit_n[++len] = t % 47, maxlen = max(maxlen, len);

	memset(f, -1, sizeof f);
	return dp(maxlen, 0, 0, 0);
}
int main(void) {

	for (int i = 0; i <= 1000; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % 47;
		}
	}

	int cases; scanf("%d", &cases);
	while (cases--) {
		LL a[3] = {0};
		LL l[3] = {0};
		LL r[3] = {0};
		for (int i = 0; i < 3; ++i) {
			cin >> a[i] >> l[i] >> r[i];
		}
		LL n; cin >> n;
		int ans = 0;
		for (int s = 0; s < (1<<3); ++s) {
			LL range[3] = {0};
			for (int i = 0; i < 3; ++i) if (s >> i & 1) {
				range[i] = l[i]-1;
			} else {
				range[i] = r[i];
			}
			int cnt = 0;
			for (int t = 0;t < 3; ++t) {
				if (s >> t & 1) ++cnt;
			}
			int c = (cnt & 1) ? -1 : 1;
			ans += c * get_ans(n, range, a);
		}
		printf("%d\n", (ans%47+47) % 47);
		ans = 0;
		for (int x1 = l[0]; x1 <= r[0]; ++x1)
			for (int x2 = l[1]; x2 <= r[1]; ++x2)
				for (int x3 = l[2]; x3 <= r[2]; ++x3) {
					if (x1+x2+x3 <= n)
						ans += (LL) C[a[0]][x1] * C[a[1]][x2] * C[a[2]][x3] % 47;
				}
		printf("%d\n", ans % 47);
	}

	return 0;
}

