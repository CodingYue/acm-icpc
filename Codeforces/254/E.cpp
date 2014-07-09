// File Name: E.cpp
// Author: YangYue
// Created Time: Sun Jul  6 22:23:37 2014
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

struct Edge {
	int a, b, c;
	Edge(){}
	Edge(int a, int b, int c)
		: a(a), b(b), c(c) {}
}edge[MaxN];
int fa[MaxN];
int n;
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int x[MaxN];
int size[MaxN];
int sumx[MaxN];
int all = 0;
bool check(int w) {
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		size[i] = 1;
		sumx[i] = x[i];
	}
	for (int i = 1; i < n; ++i) {
		int u = edge[i].a;
		int v = edge[i].b;
		int c = edge[i].c;
		if (c >= w) continue;
		int a = get(u);
		int b = get(v);
		fa[a] = b;
		size[b] += size[a];
		sumx[b] += sumx[a];
	}
	for (int i = 1; i <= n; ++i) if (fa[i] == i) {
		if (size[i] > all - sumx[i]) return false;
	}
	return true;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[i] = Edge(a, b, c);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", x + i);
		all += x[i];
	}
	int l = 0, r = INF;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid; else r = mid;
	}
	printf("%d\n", l);
	
	return 0;
}

// hehe ~


