// File Name: A.cpp
// Author: YangYue
// Created Time: Sat May 31 22:03:00 2014
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
	freopen("in","r",stdin);

	int capicity = 0;
	int n;
	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		printf("Case #%d: ", cas);
		scanf("%d %d", &n, &capicity);
		multiset<PII> SET;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		sort(a, a + n); reverse(a, a + n);
		for (int i = 0; i < n; ++i) SET.insert(MP(-a[i], i));
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (!SET.count(MP(-a[i], i))) continue;
			int tmp = -(capicity - a[i]);
			SET.erase(MP(-a[i], i));
			++res;
			if (SET.empty()) break;
			multiset<PII> :: iterator tar = SET.lower_bound(MP(tmp, -1));
			//printf("%d %d\n", tar->first, tar->second);
			if (tar != SET.end()) SET.erase(tar);
		}
		printf("%d\n", res);
	}
	
	return 0;
}

// hehe ~


