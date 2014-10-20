// File Name: B.cpp
// Author: YangYue
// Created Time: Sat Oct 11 21:34:56 2014
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
int best[MaxN];
bool flag[MaxN];
vector<int> divisors[MaxN];
int MAP[MaxN];

int main()
{
	//freopen("in","r",stdin);

	for (int i = 2; i <= 1000000; ++i) if (!flag[i]) {
		for (int j = i; j <= 1000000; j += i) {
			if (j > i) flag[j] = 1;
			divisors[j].push_back(i);
		}
	}

	int cases; scanf("%d", &cases);
	while (cases--) {
		int n = 0;
		scanf("%d", &n);
		memset(MAP, 0, sizeof MAP);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			int Max = 0;
			for (int j = 0; j < divisors[a[i]].size(); ++j) {
				Max = max(Max, MAP[divisors[a[i]][j]]);
				MAP[divisors[a[i]][j]] = i;
			}
			best[i] = max(Max, best[i-1]);
			ans = max(ans, i - best[i]);
		}
		if (ans == 1) puts("-1");
		else
		printf("%d\n", ans);
	}
	
	return 0;
}

// hehe ~


