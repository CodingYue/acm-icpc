// File Name: 2A.cpp
// Author: YangYue
// Created Time: Sat Apr 26 14:02:30 2014
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
const int MOD = (int) 1e9 + 7;

int n;
LL f[105];

int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= 100; ++i) f[i] = (LL) (i-1) * (f[i-1] + f[i-2]) % MOD;
	int cas = 0;
	while (cases--) {
		printf("Case %d: ", ++cas);
		scanf("%d", &n);
		int res = 1;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			res = (LL) res * x % MOD;
		}
		cout << (LL) res * f[n] % MOD << endl;
	}
	
	return 0;
}

// hehe ~


