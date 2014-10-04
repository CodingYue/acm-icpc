// File Name: F.cpp
// Author: YangYue
// Created Time: Mon Sep 29 00:35:14 2014
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

int x[MaxN], y[MaxN];
int main_ele[MaxN];
PII a[MaxN];

int Gauss(int n, vector<PII> &oper, int *x) {
	for (int i = 0; i < n; ++i) a[i] = MP(x[i], i+1);
	int cur = 0;
	for (int x = 31; x >= 0; --x) {
		int find = -1;
		for (int i = cur; i < n; ++i) if (a[i].first >> x & 1) {
			find = i;
			break;
		}
		if (find == -1) continue;
		main_ele[x] = cur;
		swap(a[find], a[cur]);
		for (int i = cur+1; i < n; ++i) if (a[i].first >> x & 1) {
			a[i].first ^= a[cur].first;
			oper.push_back(MP(a[i].second, a[cur].second));
		}
		++cur;
	}
	int res = n - cur;
	cur = 0;
	for (int x = 31; x >= 0; --x) {
		if (!(a[cur].first >> x & 1)) continue;
		for (int i = cur-1; i >= 0; --i) if (a[i].first >> x & 1) {
			a[i].first ^= a[cur].first;
			oper.push_back(MP(a[i].second, a[cur].second));
		}
		++cur;
	}
	return res;
}
bool is_main[MaxN];
int seq[MaxN];
bool vis[32];
bool used[MaxN];
int main()
{
	freopen("in","r",stdin);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", x + i);
	for (int i = 0; i < n; ++i) scanf("%d", y + i);
	vector<PII> ans;
	memset(main_ele, -1, sizeof main_ele);
	int remain = Gauss(n, ans, x);

	for (int i = 0; i < n; ++i)
		for (int x = 31; x >= 0; --x) if (y[i] >> x & 1) vis[x] = 1;

	for (int i = 31; i >= 0; --i) if (!vis[i]) main_ele[i] = -1;
	for (int i = 31; i >= 0; --i) if (main_ele[i] != -1) is_main[a[main_ele[i]].second] = 1;

	int m = 0;
	for (int i = 1; i <= n; ++i) if (!is_main[i]) {
		ans.push_back(MP(i, i));
		seq[m++] = i;
	}

	sort(y, y + n);
	int cnt = 0;
	for (int i = n - 1; i >= 0 && y[i] != 0; --i) {
		int x = 0;
		for (x = 31; x >= 0; --x) if (y[i] >> x & 1) break;
		int tmp = main_ele[x];
		if (tmp == -1) {
			puts("-1");
			return 0;
		}
		int p = 0;
		if (i > 0 && (y[i-1] >> x & 1)) {
			if (cnt >= m) {
				puts("-1");
				return 0;
			}
			p = seq[cnt++];
			ans.push_back(MP(p, a[tmp].second));
		}
		else p = a[main_ele[x]].second;

		used[p] = 1;

		int now = a[main_ele[x]].first;
		for (int t = x-1; t >= 0; --t) if (y[i] >> t & 1) {
			if (now >> t & 1) continue;
			int q = main_ele[t];
			if (q == -1) {
				puts("-1");
				return 0;
			}
			now ^= a[q].first;
			ans.push_back(MP(p, a[q].second));
		} else {
			if (!(now >> t & 1)) continue;
			int q = main_ele[t];
			if (q == -1) {
				puts("-1");
				return 0;
			}
			now ^= a[q].first;
			ans.push_back(MP(p, a[q].second));
		}
	}
	for (int i = 1; i <= n; ++i) if (!used[i]) ans.push_back(MP(i,i));
	printf("%d\n", (int) ans.size());
	for (auto x : ans) {
		printf("%d %d\n", x.first, x.second);
	}

	return 0;
}

// hehe ~


