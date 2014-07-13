// File Name: A.cpp
// Author: YangYue
// Created Time: Sun Jul 13 21:00:28 2014
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

int f[MaxN], g[MaxN], a[MaxN];

int main()
{
	//freopen("in","r",stdin);

	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		if (i > 1 && a[i-1] < a[i]) f[i] = f[i-1] + 1;
	}

	for (int i = n; i >= 1; --i) {
		g[i] = 1;
		if (i < n && a[i] < a[i+1]) g[i] = g[i+1] + 1;
	}

	int ans = 0;
	f[0] = g[n+1] = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			ans = max(ans, g[i+1] + 1);
		} else
		if (i == n) {
			ans = max(ans, f[i-1] + 1);
		}
		else {
			ans = max(ans, f[i-1] + 1);
			ans = max(ans, g[i+1] + 1);
			if (a[i+1] - a[i-1] > 1) {
				ans = max(ans, f[i-1] + g[i+1] + 1);
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}

// hehe ~


