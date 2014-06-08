// File Name: E.cpp
// Author: YangYue
// Created Time: Thu Jun  5 16:46:09 2014
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
const int mod = (int) 1e9 + 7;

int fac[MaxN];
int invfac[MaxN];
int miu[MaxN];
int powmod(int a, int t, int mod) {
	int res = 1;
	for (; t; t >>= 1, a = (LL) a * a % mod)
		if (t & 1) res = (LL) res * a % mod;
	return res;
}
void pre(int n) {
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = (LL) fac[i-1] * i % mod;
		invfac[i] = powmod(fac[i], mod - 2, mod);
	}
	miu[1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i)
			miu[j] -= miu[i];
	}
}
int C(int n, int m) {
	if (n < 0 || m > n || m < 0) return 0;
	return (LL) fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
int main()
{
	//freopen("in","r",stdin);

	pre(100000);
	int Q; scanf("%d", &Q);
	while (Q--) {
		int n, f; scanf("%d %d", &n, &f);
		int res = 0;
		for (int t = 1; t * t <= n; ++t) if (n % t == 0) {
			res = (res + (LL) miu[t] * C(n / t - 1, f - 1) % mod) % mod;
			if (t * t != n) res = (res + (LL) miu[n / t] * C(t - 1, f - 1) % mod) % mod;
		}
		printf("%d\n", (res + mod) % mod);
	}
	
	return 0;
}

// hehe ~


