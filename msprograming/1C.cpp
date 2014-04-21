// File Name: 1C.cpp
// Author: YangYue
// Created Time: Sun Apr 20 14:08:45 2014
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

const int bitnum = 13;
int mod;
long long f[2][1<<bitnum][2];
int get(int n) {
	long long res = 0;
	for (int i = 0; i < 13; ++i) {
		memset(f, 0, sizeof f);
		f[0][0][0] = 1;
		int now = 0, old = 1;
		for (int t = 1; t <= n; ++t) {
			swap(now, old);
			for (int z = 0; (z << i) < 8192; ++z)
			for (int b = 0; b < 2; ++b) {
				int num = t >> i;
				f[now][z][b] = 0;
				if (t <= n) {
					f[now][z][b] += f[old][z^num][b^(num&1)];
					f[now][z][b] += f[old][z^num][b];
				}
				f[now][z][b] += f[old][z][b];
				f[now][z][b] %= mod;
				if (t == n && z == 1 && b == 0) {
					res = (res + f[now][z][b]) % mod;
				}
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; ++i) ans = (LL) ans * 3 % mod;
	return (ans - res + mod) % mod;
}

int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		int n;
		scanf("%d %d", &n, &mod);
		printf("Case %d: %d\n", ++cas, get(n));
	}

	return 0;
}

// hehe ~


