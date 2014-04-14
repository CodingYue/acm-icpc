// File Name: 1A.cpp
// Author: YangYue
// Created Time: Thu Apr 10 18:36:54 2014
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

bool flag[MaxN];
int pm = 0;
int prime[MaxN];
int miu[MaxN];

LL fpow(LL a, LL b) {
	LL res = 1;
	for (int i = 0; i < b; ++i) res = res * a;
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	miu[1] = 1;
	for (int i = 2; i <= 20; ++i) {
		if (!flag[i]) {
			prime[pm++] = i;
			miu[i] = -1;
		}
		for (int j = 0; j < pm && prime[j] * i <= 20; ++j) {
			flag[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				miu[i * prime[j]] = 0;
				break;
			}
			miu[i * prime[j]] = -1 * miu[i];
		}
		
	}
	while (cases--) {
		int A, B; scanf("%d %d", &A, &B);
		LL ans = 0;
		for (int t = 1; t <= B; ++t) if (__gcd(t, B) == 1) {
			for (int d = 1; d <= B / t; ++d) {
				ans += miu[d] * fpow((B / (d * t)), A);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

// hehe ~


