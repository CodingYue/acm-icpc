// File Name: Blarge.cpp
// Author: YangYue
// Created Time: Sun May  4 00:39:18 2014
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

int A, B, K;
LL f[33][2][2][2];
LL dp(int i, bool fa, bool fb, bool fk) {
	if (i < 0) return 1;
	if (f[i][fa][fb][fk] != -1) return f[i][fa][fb][fk];
	LL res = 0;
	for (int a = 0; a <= (!fa ? (A >> i & 1) : 1); ++a)
	for (int b = 0; b <= (!fb ? (B >> i & 1) : 1); ++b) {
		int x = a & b;
		if (!fk && (x > (K >> i & 1))) continue;
		res += dp(i - 1, fa | (a < (A >> i & 1)), fb | (b < (B >> i & 1)), fk | (x < (K >> i & 1)));
	}
	f[i][fa][fb][fk] = res;
	return res;
}

int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		memset(f, -1, sizeof f);
		printf("Case #%d: ", ++cas);
		scanf("%d %d %d", &A, &B, &K);
		--A, --B, --K;
		printf("%lld\n", dp(31, 0, 0, 0));
	}
	
	return 0;
}

// hehe ~


