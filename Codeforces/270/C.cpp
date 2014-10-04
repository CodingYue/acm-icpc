// File Name: C.cpp
// Author: YangYue
// Created Time: Sun Sep 28 23:48:16 2014
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

pair<string, string> a[MaxN];

bool f[MaxN][2];
int p[MaxN];

int main()
{
	//freopen("in","r",stdin);

	int n;
	int m = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 1; i <= n; ++i) scanf("%d", p + i);
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		int pre = p[i-1];
		int now = p[i];
		if (a[now].first > a[pre].first) f[i][0] |= f[i-1][0];
		if (a[now].second > a[pre].second) f[i][1] |= f[i-1][1];
		if (a[now].first > a[pre].second) f[i][0] |= f[i-1][1];
		if (a[now].second > a[pre].first) f[i][1] |= f[i-1][0];
	}

	if (f[n][0] || f[n][1]) puts("YES");
	else puts("NO");

	return 0;
}

// hehe ~


