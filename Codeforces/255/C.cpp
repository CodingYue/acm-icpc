// File Name: C.cpp
// Author: YangYue
// Created Time: Sun Jul 13 21:24:11 2014
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
typedef pair<int, int> PII;
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
const int MOD = (int) 1e9 + 9;

int n, m;
int a[MaxN];
int orisum[MaxN];
int fib[MaxN];
int sum_fib[MaxN];
struct Tnode {
	int a, b, sum;
	Tnode(){}
	Tnode(int a, int b, int sum) : a(a), b(b), sum(sum) {}
} Tree[MaxN * 2];
void build(int p, int l, int r) {
	Tree[p].a = Tree[p].b = Tree[p].sum = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(lch(p), l, mid);
	build(rch(p), mid + 1, r);
}
PII get_Fib(int a, int b, int len) {
	if (len == 0) return MP(a, b);
	if (len == 1) return MP(b, (a + b) % MOD);
	--len;
	LL a1 = (LL) a * fib[len-1] % MOD + (LL) b * fib[len] % MOD;
	LL a2 = (LL) a * fib[len] % MOD + (LL) b * fib[len+1] % MOD;
	return MP(a1 % MOD, a2 % MOD);
}
int get_sum(int a, int b, int len) {
	if (len == 0) return a;
	if (len == 1) return (a + b) % MOD;
	LL tmp = (LL) a * fib[len] % MOD + (LL) b * (fib[len+1] -1) % MOD;
	return tmp % MOD;
}
void add(int &a, int b) {
	a += b;
	if (a >= MOD) a %= MOD;
}
void update(int p, int l, int r) {
	Tree[p].sum = get_sum(Tree[p].a, Tree[p].b, r - l);
	if (l != r) {
		add(Tree[p].sum, (Tree[lch(p)].sum + Tree[rch(p)].sum) % MOD);
	}
}
void pushdown(int p, int l, int r) {
	if (l == r) return;
	add(Tree[lch(p)].a, Tree[p].a);
	add(Tree[lch(p)].b, Tree[p].b);
	int mid = (l + r) >> 1;
	PII tmp = get_Fib(Tree[p].a, Tree[p].b, mid + 1 - l);
	add(Tree[rch(p)].a, tmp.first);
	add(Tree[rch(p)].b, tmp.second);
	Tree[p].a = Tree[p].b = 0;
	update(lch(p), l, mid);
	update(rch(p), mid + 1, r);
}
void modify(int p, int l, int r, int i, int j) {
	if (i <= l && r <= j) {
		PII tmp = get_Fib(1, 1, l - i);
		add(Tree[p].a, tmp.first);
		add(Tree[p].b, tmp.second);
		update(p, l, r);
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) >> 1;
	if (i <= mid) modify(lch(p), l, mid, i, j);
	if (j > mid) modify(rch(p), mid + 1, r, i, j);
	update(p, l, r);
}
int ask(int p, int l, int r, int i, int j) {
	if (i <= l && r <= j) {
		update(p, l, r);
		return Tree[p].sum;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, r);
	int res = 0;
	if (i <= mid) add(res, ask(lch(p), l, mid, i, j));
	if (j > mid) add(res, ask(rch(p), mid + 1, r, i, j));
	update(p, l, r);
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		orisum[i] = (orisum[i-1] + a[i]) % MOD;
	}
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= n + 10; ++i) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	sum_fib[0] = 1;
	for (int i = 1; i <= n + 10; ++i) sum_fib[i] = (sum_fib[i-1] + fib[i]) % MOD;
	while (m--) {
		int op, l, r; scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			modify(1, 1, n, l, r);
		} else {
			LL ans = ask(1, 1, n, l, r) + orisum[r] - orisum[l-1];
			ans = (ans % MOD + MOD) % MOD;
			printf("%d\n", (int) ans);
		}
	}
	
	return 0;
}

// hehe ~


