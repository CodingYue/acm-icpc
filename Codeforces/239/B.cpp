// File Name: B.cpp
// Author: YangYue
// Created Time: Sun Mar 30 15:52:40 2014
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

int p[1111], f[1111][1111];
int dp(int l, int r) {
	if (l == r && p[l] == l) return 1;
	if (f[l][r] != -1) return f[l][r];
	f[l][r] = 0;
	if (l == r) f[l][r] = (2 + dp(p[l], l - 1)) % MOD;
	else if (p[l] == l) f[l][r] = (2 + dp(l + 1,r)) % MOD;
	else f[l][r] = (1 + dp(p[l],l - 1) + 2 + dp(l + 1,r)) % MOD;
	return f[l][r];
}
int main()
{
	//freopen("in","r",stdin);

	int n; cin >> n;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; ++i) scanf("%d", p + i);
	cout << (dp(1, n) + 1) % MOD << endl;
	
	return 0;
}

// hehe ~


