// File Name: B.cpp
// Author: YangYue
// Created Time: Sun Sep 28 23:43:19 2014
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

int a[MaxN];

int main()
{
	//freopen("in","r",stdin);

	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	
	int ans = 0;
	for (int i = n - 1; i >= 0; ) {
		int j, cnt = 0;
		for (j = i, cnt = 0; j >= 0 && cnt < k; ++cnt, --j);
		ans += 2 * (a[i] - 1);
		i = j;
	}
	printf("%d\n", ans);
	
	return 0;
}

// hehe ~


