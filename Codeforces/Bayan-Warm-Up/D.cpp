// File Name: D.cpp
// Author: YangYue
// Created Time: Sun Oct  5 21:30:38 2014
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

map<int, LL> ans;
int n;
int a[MaxN];
PII Stack[MaxN], newStack[MaxN];

int main()
{
	freopen("in","r",stdin);

	int top = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		Stack[++top] = MP(a[i], 1);
		int newTop = 0;
		for (int x = 1; x <= top; ++x) newStack[x] = make_pair(__gcd(Stack[x].first, a[i]), Stack[x].second);
		for (int x = 1; x <= top; ) {
			int y;
			int cnt = 0;
			for (y = x; y <= top && newStack[x].first == newStack[y].first; ++y) cnt += newStack[y].second;
			Stack[++newTop] = MP(newStack[x].first, cnt);
			x = y;
		}
		top = newTop;
		for (int x = 1; x <= top; ++x) ans[Stack[x].first] += Stack[x].second;
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int x; scanf("%d", &x);
		printf("%lld\n", ans[x]);
	}
	
	return 0;
}

// hehe ~


