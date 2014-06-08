// File Name: A.cpp
// Author: YangYue
// Created Time: Sat May 24 15:00:14 2014
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
int a[MaxN];
LL cnt[MaxN], all[MaxN];
multiset<LL> SET[MaxN];

int main()
{
	freopen("in","r",stdin);

	
	LL sum = 0;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		if (i > 1) {// && a[i] != a[i-1]) {
			sum += abs(a[i] - a[i-1]);
			cnt[a[i]] += abs(a[i] - a[i-1]);
			SET[a[i]].insert(a[i-1]);
			all[a[i]] += a[i-1];
		}
		if (i < n) {// && a[i] != a[i+1]) {
			all[a[i]] += a[i+1];
			SET[a[i]].insert(a[i+1]);
			cnt[a[i]] += abs(a[i] - a[i+1]);
		}
	}
	LL tsum = sum;
	LL ans = sum;
	for (int i = 1; i <= m; ++i) {
		int target = (SET[i].size() + 1) / 2;
		int k = 0;
		LL sum = 0;
		for (multiset<LL> :: iterator it = SET[i].begin(); it != SET[i].end(); ++it) {
			++k;
			sum += *it;
			if (k == target) {
				LL tmp = target * *it - sum + all[i] - sum - (SET[i].size() - target) * *it;
				ans = min(ans, tsum - cnt[i] + tmp);
				break;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}

// hehe ~


