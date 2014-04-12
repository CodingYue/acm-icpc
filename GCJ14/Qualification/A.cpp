// File Name: A.cpp
// Author: YangYue
// Created Time: Sat Apr 12 22:08:45 2014
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
int a[4][4], b[4][4];

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);

	int cases; scanf("%d", &cases);

	int TK = 0;
	while (cases--) {
		scanf("%d", &n);
		for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &a[i][j]);
		}
		scanf("%d", &m);
		for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) scanf("%d", &b[i][j]);

		--n; --m;
		int cnt = 0;
		int ans = -1;
		for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) if (a[n][i] == b[m][j]) {
			++cnt;
			ans = a[n][i];
		}
		printf("Case #%d: ", ++TK);
		if (cnt == 0) puts("Volunteer cheated!");
		else if (cnt == 1) printf("%d\n", ans);
		else puts("Bad magician!");

	}
	
	return 0;
}

// hehe ~


