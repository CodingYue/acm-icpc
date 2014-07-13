// File Name: B.cpp
// Author: YangYue
// Created Time: Sun Jul 13 21:34:59 2014
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

const int MaxN = 1005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n, m, k, p;
int row[MaxN], col[MaxN];
int a[MaxN][MaxN];
LL myrow[MaxN*MaxN], mycol[MaxN*MaxN];
void calc(LL *c, int n, int m, int *a) {
	priority_queue<int> heap;
	for (int i = 0; i < n; ++i) heap.push(a[i]);
	for (int t = 1; t <= k; ++t) {
		int cur = heap.top();
		heap.pop();
		c[t] = c[t-1] + cur;
		cur -= m * p;
		heap.push(cur);
	}
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d %d %d", &n, &m, &k, &p);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	calc(myrow, n, m, row);
	calc(mycol, m, n, col);

	LL ans = -LINF;
	for (int t = 0; t <= k; ++t) {
		LL tmp = myrow[t] - (LL) t * (k - t) * p + mycol[k-t];
		ans = max(ans, tmp);
	}
	printf("%I64d\n", ans);
	
	return 0;
}

// hehe ~


