// File Name: 3774.cpp
// Author: YangYue
// Created Time: Sun Jun 29 22:05:10 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const int mod = (int) 1e9 + 9;

LL fpow(int a, LL t, int mod) {
	int res = 1;
	for (; t; t >>= 1, a = (LL) a * a % mod)
		if (t & 1) res = (LL) res * a % mod;
	return res;
}
int find_root(int n, int p) {
	n %= p;
	if (n == 0) return 0;
	if (fpow(n, (p - 1) / 2, p) != 1) return -1;
	int Q = p - 1, S = 0;
	for (; Q % 2 == 0; Q >>= 1) ++S;
	if (S == 1) return fpow(n, (p + 1) / 4, p);
	int z;
	while (1) {
		z = 1 + rand() % (p - 1); 
		if (fpow(z, (p - 1) / 2, p) != 1) break;
	}
	int c = fpow(z, Q, p);
	int R = fpow(n, (Q + 1) / 2, p);
	int t = fpow(n, Q, p);
	int m = S;
	while (1) {
		if (t % p == 1) break;
		int i = 1;
		for (i = 1; i < m; ++i) if (fpow(t, 1 << i, p) == 1) break;
		int b = fpow(c, 1 << (m - i - 1), p);
		R = (LL) R * b % p;
		t = (LL) t * b % p * b % p;
		c = (LL) b * b % p;
		m = i;
	}
	return (R % p + p) % p;
}
LL invfac[1000001], fac[1000001];;
LL C(int n, int k) {
	return fac[n] * invfac[n-k] % mod * invfac[k] % mod;
}
LL calc(LL p1, LL p2, int a, int b, LL n) {
	LL p = fpow(p1, a, mod) * fpow(p2, b, mod) % mod;
	if (p == 1) return n % mod;
	LL res = (fpow(p, n + 1, mod) - p + mod) % mod * fpow(p - 1, mod - 2, mod) % mod;
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= 100000; ++i) {
		fac[i] = fac[i-1] * i % mod;
		invfac[i] = fpow(fac[i], mod - 2, mod);
	}
	LL x = find_root(5, mod);
	LL invx = fpow(x, mod - 2, mod);
	LL p1 = (LL) (1 + x) * fpow(2, mod - 2, mod) % mod;
	LL p2 = ((LL) (1 - x) * fpow(2, mod - 2, mod) % mod + mod) % mod;

	int cases; scanf("%d", &cases);
	while (cases--) {
		LL n, k; scanf("%lld %lld", &n, &k);
		LL res = 0;
		for (int i = 0; i <= k; ++i) {
			LL c = C(k, i);
			if ((k - i) % 2 == 1) c *= -1;
			res = (res + c * calc(p1, p2, i, k - i, n) % mod + mod) % mod;
		}
		printf("%lld\n", res * fpow(invx, k, mod) % mod);
	}

	return 0;
}

// hehe ~


