// File Name: C.cpp
// Author: YangYue
// Created Time: Sun Jul  6 21:54:44 2014
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
struct OP {
	int l, r, c;
	OP(){}
	OP(int l, int r, int c)
		: l(l), r(r), c(c) {}
	bool operator < (const OP &b) const {
		if (l != b.l) return l < b.l;
		if (r != b.r) return r < b.r;
		return c < b.c;
	}
};
long long a[MaxN], b[MaxN];
void add(long long *C, LL x, LL val) {
	for (; x <= 1000000; x += lowbit(x)) C[x] += val;
}
LL sum(LL *C, LL x) {
	LL res = 0;
	for (; x > 0; x -= lowbit(x)) res += C[x];
	return res;
}
void modify(LL l, LL r, LL c) {
	add(a, l, c);
	add(b, l, (LL) (l-1)*c);
	add(a, r+1, -c);
	add(b, r+1, -(LL) r*c);
}
LL ask(LL l, LL r) {
	LL tmpr = (LL) r * sum(a, r) - sum(b, r);
	LL tmpl = (LL) (l - 1) * sum(a, l - 1) - sum(b, l - 1);
	return tmpr - tmpl;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d", &n, &m);
	set<OP> Set;
	for (int i = 1; i <= n; ++i) Set.insert(OP(i, i, i));
	while (m--) {
		int op, l, r, x;
		scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			scanf("%d", &x);
			set<OP> :: iterator it = Set.upper_bound(OP(l, INF, INF));
			--it;
			for (; it != Set.end();) {
				if (it->l > r) break;
				modify(max(l, it->l), min(r, it->r), abs(it->c - x));
				if (it->l < l)
					Set.insert(OP(it->l, l - 1, it->c));
				if (it->r > r) 
					Set.insert(OP(r + 1, it->r, it->c));
				OP tmp = *it;
				++it;
				Set.erase(Set.find(tmp));
			}
			Set.insert(OP(l, r, x));
		} else {
			printf("%I64d\n", ask(l, r));
		}
	}
	
	return 0;
}

// hehe ~


