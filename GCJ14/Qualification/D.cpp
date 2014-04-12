// File Name: D.cpp
// Author: YangYue
// Created Time: Sat Apr 12 22:31:39 2014
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

int n;
double a[1005], b[1005];
bool used[1005];
int solve(double *a, double *b) {
	int res = 0;
	memset(used, 0, sizeof used);
	for (int i = 0; i < n; ++i) {
		bool find = 0;
		for (int j = 0; j < n; ++j) if (!used[j] && b[j] > a[i]) {
			used[j] = 1;
			find = 1;
			break;
		}
		if (!find) ++res;
	}
	return res;
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int Tk = 0;
	while (cases--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", a + i);
		for (int i = 0; i < n; ++i) scanf("%lf", b + i);
		sort(a, a + n);
		sort(b, b + n);
		printf("Case #%d: %d %d\n", ++Tk, n - solve(b, a), solve(a, b));
	}
	
	return 0;
}

// hehe ~


