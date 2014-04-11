// File Name: quliB.cpp
// Author: YangYue
// Created Time: Fri Apr 11 23:37:13 2014
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

int main()
{
//	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int Case = 0;
	while (cases--) {
		LL n; scanf("%d", &n);
		n %= MOD;
		LL a = n * (n + 1) / 2 % MOD;
		LL b = n * (n + 1) % MOD * (2 * n + 1) % MOD * 166666668ll % MOD;
		printf("Case %d: ", ++Case);
		cout << ((a * a % MOD * a % MOD - 3 * a * b % MOD + 3 * a * a % MOD) % MOD + MOD) % MOD << endl;

	}
	
	return 0;
}

// hehe ~


