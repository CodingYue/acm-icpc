// File Name: B.cpp
// Author: YangYue
// Created Time: Sat Sep 20 21:21:16 2014
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

int fa[MaxN];
int p[MaxN];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	fa[a] = b;
}
int ans[MaxN];
bool check(const vector<int> &contains, int A, int B) {
	set<int> SET;
	for (auto x : contains) SET.insert(p[x]);
	bool canA = 1;
	bool canB = 1;
	for (auto x : contains) {
		if (!SET.count(A - p[x])) canA = 0;
		if (!SET.count(B - p[x])) canB = 0;
	}
	if (!canA && !canB) return 0;
	if (canA) {
		for (auto x : contains) ans[x] = 0;
	} else {
		for (auto x : contains) ans[x] = 1;
	}
	return 1;
}
vector<int> contains[MaxN];
int main()
{
	//freopen("in","r",stdin);

	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	map<int, int> pos;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		pos[p[i]] = i;
		fa[i] = i;
	}

	for (int i = 1; i <= n; ++i) {
		int x = a - p[i];
		if (pos[x] != 0) merge(i, pos[x]);
		int y = b - p[i];
		if (pos[y] != 0) merge(i, pos[y]);
	}

	for (int i = 1; i <= n; ++i) {
		int x = get(i);
		contains[x].push_back(i);
	}

	bool can = 1;
	for (int i = 1; i <= n; ++i) if (fa[i] == i) {
		can &= check(contains[i], a, b);
	}
	if (can) {
		puts("YES");
		for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	} else {
		puts("NO");
	}
	
	return 0;
}

// hehe ~


