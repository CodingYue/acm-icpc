// File Name: C.cpp
// Author: YangYue
// Created Time: Tue Aug 26 22:41:55 2014
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

int n;
int C[MaxN];
void add(int x, int v) {
	for (; x <= 1000000; x += lowbit(x)) C[x] += v;
}
int sum(int x) {
	int res = 0;
	if (x <= 0) return 0;
	for (; x ; x -= lowbit(x)) res += C[x];
	return res;
}
int ask(int l, int r) {
	return sum(r) - sum(l);
}
int main()
{
	//freopen("in","r",stdin);
	
	int Q;
	scanf("%d %d", &n, &Q);

	for (int i = 1; i <= n; ++i) {
		add(i, 1);
	}
	int l = 0, r = n;
	bool flip = 0;
	while (Q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int p; scanf("%d", &p);
			int cp = p;
			int curwidth = r - l;
			if (flip) p = curwidth - p;
			if (cp * 2 > curwidth) flip ^= 1;
			if (p * 2 > curwidth) {
				for (int i = r - 1; i >= l + p; --i) {
					int c = ask(i, i + 1);
					add(2*(l+p)-i, c);
				}
				r = l + p;
			} else {
				for (int i = l; i < p + l; ++i) {
					int c = ask(i, i + 1);
					add(2*(l+p)-i, c);
				}
				l += p;
			}
		}
		if (op == 2) {
			int cl, cr; scanf("%d %d", &cl, &cr);
			int curwidth = r - l;
			if (flip) {
				cl = curwidth - cl;
				cr = curwidth - cr;
				swap(cl, cr);
			}
			int ans = ask(l + cl, l + cr);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}

// hehe ~


