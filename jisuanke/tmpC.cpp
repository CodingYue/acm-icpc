#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))

const int INF = (int) 1e9+1;

int f[21][48][8];

int bit_A[3][111];
int bit_R[3][111];
int bit_n[111];

int C[111][111];
int dp(int i, int remain, int mask) {
	if (i == 0) {
		return 1;
	}
	if (f[i][remain][mask] != -1) {
		return f[i][remain][mask];
	}
	int &res = f[i][remain][mask];
	res = 0;
	int range[3] = {0};
	for (int x = 0; x < 3; ++x) {
		if (!(mask >> x & 1)) {
			range[x] = bit_R[x][i];
		} else {
			range[x] = 46;
		}
	}
	remain = remain * 47 + bit_n[i];
	for (int a = 0; a <= range[0]; ++a)
		for (int b = 0; b <= range[1]; ++b)
			for (int c = 0; c <= range[2]; ++c) {
				if (a+b+c > remain) continue;
				int next = remain-a-b-c;
				if (next >= 4) next = 4;
				int nextmask = mask;
				if (a < range[0]) nextmask |= 1;
				if (b < range[1]) nextmask |= 2;
				if (c < range[2]) nextmask |= 4;
				int con = 1;
				
				con *= C[bit_A[0][i]][a];
				con *= C[bit_A[1][i]][b];
				con *= C[bit_A[2][i]][c];
				res += dp(i-1, next, nextmask) * con;
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
	return dp(maxlen, 0, 0);
}
int main(void) {

	for (int i = 0; i <= 100; ++i) {
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
	}

	return 0;
}



