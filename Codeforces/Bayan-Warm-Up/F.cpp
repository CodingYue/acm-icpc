// File Name: F.cpp
// Author: YangYue
// Created Time: Sun Oct  5 22:58:20 2014
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
typedef pair<int,int> pii;
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

map<pii, int> MAP;
struct Status {
	int mask;
	pii who;
	Status(){}
	Status(int mask, pii who) : mask(mask), who(who) {}
	bool operator < (const Status &b) const {
		if (mask != b.mask) return mask > b.mask;
		return who < b.who;
	}
	bool operator == (const Status &b) const {
		return mask == b.mask && who == b.who;
	}
};
set<Status> SET;
int fa[MaxN];
int seq[MaxN];
vector<int> events[MaxN];
vector<pii> edges[MaxN];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void add(int x, int y, int mask) {
	printf("%d %d %d\n", x, y, mask);
	if (x == y) return;
	if (x > y) swap(x, y);
	pii cur = pii(x, y);
	if (!MAP.count(cur)) {
		MAP[cur] = mask;
		SET.insert(Status(mask, cur));
		edges[x].push_back(pii(y, mask));
		edges[y].push_back(pii(x, mask));
		return;
	}
	if (MAP[cur] == 3) return;
	if (MAP[cur] != mask) {
		SET.erase(Status(MAP[cur], cur));
		MAP[cur] |= mask;
		SET.insert(Status(MAP[cur], cur));
	}
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (edges[a].size() < edges[b].size()) swap(a, b);
	for (auto x : edges[a]) add(x.first, b, x.second);
	fa[a] = b;
}
void direct(int *x, int n, int p) {
	int m = 0;
	for (int i = 0; i < n; ++i) {
		seq[m++] = x[i];
		seq[m++] = x[i]-1;
		seq[m++] = x[i]+1;
	}
	sort(seq, seq + m);
	m = unique(seq, seq + m) - seq;
	for (int i = 0; i < n; ++i) x[i] = lower_bound(seq, seq + m, x[i]) - seq;
	
	for (int i = 0; i < m; ++i) events[i].clear();

	for (int i = 0; i < n; ++i) {
		events[x[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		for (auto it : events[x[i]]) add(it, i, p);
		for (auto it : events[x[i]-1]) add(it, i, p);
		for (auto it : events[x[i]+1]) add(it, i, p);
	}
}
int x[MaxN], y[MaxN];
int main() {

	freopen("in","r",stdin);

	int n ; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);

	direct(x, n, 1);
	direct(y, n, 2);
	for (int i = 0; i < n; ++i) fa[i] = i;

	while(SET.size()) {
		Status first = *SET.begin();
		if (first.mask != 3) break;
		SET.erase(first);
		merge(first.who.first, first.who.second);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) if (i == get(i)) ++ans;
	printf("%d\n", ans);

	return 0;
}
