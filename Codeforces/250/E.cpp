// File Name: E.cpp
// Author: YangYue
// Created Time: Thu Jun  5 17:17:44 2014
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

int n, m;
int f[2][1005], c[1005];

int main()
{
	freopen("in","r",stdin);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", c + i);
	sort(c, c + n);
	int now = 0, next = 1;
	for (int k = 0; k < n; ++k) {
		memset(f[next], 0, sizeof f[next]);
		f[now][0] = f[next][0] = 1;
		for (int s = 1; s <= m; ++s) {
			int t = s - c[k];
			for (int p = 0; p <= t; ++p)
				f[next][s] += f[next][t-p] * f[next][p] + 
							  f[next][t-p] * f[now][p] +
							  f[now][t-p] * f[next][p];
		}
		for (int s = 1; s <= m; ++s) f[next][s] += f[now][s];
		swap(next, now);
	}
	for (int s = 1; s <= m; ++s) printf("%d\n", f[now][s]);
	/*
	for (int s = 1; s <= m; ++s) {
		for (int k = 0; k < n; ++k) {
			int t = s - c[k];
			for (int p = 0; p <= t; ++p)
				f[s] += f[p] * f[t-p];
		}
		printf("%d\n", f[s]);
	}*/
	
	return 0;
}

// hehe ~


