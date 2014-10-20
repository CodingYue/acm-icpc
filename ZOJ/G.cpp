// File Name: G.cpp
// Author: YangYue
// Created Time: Sun Oct 12 19:00:51 2014
//headers 
#include <assert.h>
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

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL res = ex_gcd(b, a % b, y, x);
	y -= x*(a/b);
	return res;
}
LL get_sqrt(LL x) {
	if (x <= 0) return 0;
	LL l = 0, r = 1e9;
	while (l + 1 < r) {
		LL mid = (l + r) >> 1;
		if (mid*mid <= x) l = mid; else r = mid;
	}
	return l;
}
PLL get(long long A, long long B, long long C, bool &yes) {
	long long delta = B*B - 4*A*C;
	if (delta < 0) {
		yes = false;
		return MP(0, 0);
	}
	double x1 = (-B+sqrt(delta))/(2.*A);
	double x2 = (-B-sqrt(delta))/(2.*A);
	if (x1 > x2) swap(x1, x2);
	LL y1 = x1+1;
	LL y2 = x2-1;
	while (A*(y1-1)*(y1-1)+B*(y1-1)+C <= 0) --y1;
	while (A*(y2+1)*(y2+1)+B*(y2+1)+C <= 0) ++y2;
	return MP(y1, y2);
}
LL check(LL a, LL b, LL c, LL R) {
	a = abs(a); b = abs(b); c = abs(c);
	if (c > 1000000000ll) return 0;
	if (b == 0) swap(a, b);
	LL gcd = __gcd(a, b);
	if (c % gcd != 0) return 0;
	if (a == 0) {
		LL y = c / b;
		LL remain = R*R-y*y;
		if (remain < 0) return 0;
		return get_sqrt(remain)*2+1;
	}
	LL x0, y0;
	a /= gcd; b /= gcd; c /= gcd;
	ex_gcd(abs(a), abs(b), x0, y0);
	x0 *= c;
	y0 *= c;

	LL A = a*a+b*b;
	LL B = 2*x0*b - 2*y0*a;
	LL C = x0*x0 + y0*y0 - R*R;

	bool yes = true;
	PLL res = get(A, B, C, yes);
	if (!yes) return 0;
	if (res.second < res.first) return 0;
	return res.second - res.first + 1;
}
int brute(LL x1, LL y1, LL x2, LL y2, LL R, LL S) {
	int cnt = 0;
	for (LL x = -R; x <= R; ++x)
		for (LL y = -R; y <= R; ++y) {
			if (x*x+y*y<=R*R && S == abs(((x-x1)*(y-y2)-(x-x2)*(y-y1)))) ++cnt;
		}
	return cnt;
}
int main()
{

	/*
	LL a = 304, b = -43, c = 78576, r = 587;
	{
		printf("%lld ", check(a, b, c, r));
		int cnt = 0;
		for (int x = -r; x <= r; ++x)
			for (int y = -r; y <= r; ++y) {
				if (x*x+y*y <= r*r && a*x+b*y == c) ++cnt;
			}
		printf("%d\n", cnt);
	}
	*/
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int idx = 0;
	while (cases--) {
		printf("%d ", ++idx);
		int S;
		scanf("%d", &S);

		int x0, y0, R; scanf("%d %d %d", &x0, &y0, &R);
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 -= x0; x2 -= x0;
		y1 -= y0; y2 -= y0;
		int ans1 = brute(x1, y1, x2, y2, R, S);
		printf("%d ", ans1);
		int a = (x2 - x1);
		int b = (y1 - y2);
		LL area = ((LL)x1*y2-(LL)x2*y1);
		LL ans = 0;
		ans += check(a, b, S - area, R);
		ans += check(a, b, -S - area, R);
		printf("%lld\n", ans);
		assert(ans1 == ans);
	}
	
	return 0;
}

// hehe ~


