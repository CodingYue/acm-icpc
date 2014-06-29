// File Name: C.cpp
// Author: YangYue
// Created Time: Wed Jun 25 13:17:51 2014
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

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

int n;
struct Point {
	double x, y;
	Point(){}
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
	Point operator - (const Point &b) { return Point(x - b.y, y - b.y); }
	Point operator * (const double &b) { return Point(x * b, y * b); }
	Point operator / (const double &b) { return Point(x / b, y / b); }
	double operator * (const Point &b) { return x * b.y - y * b.x; }
	void init() { scanf("%lf %lf", &x, &y); }
} hull[2005];

int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		hull[i].init();
	}
	hull[n] = hull[0];

	Point target = hull[0];
	double area = 0;
	for (int i = 0; i < n; ++i) {
		area += hull[i] * hull[i+1] / 2;
	}

	if (area < 0) {
		reverse(hull, hull + n);
		hull[n] = hull[0];
	}
	
	area = 0;
	double cx = 0.0;
	for (int i = 0; i < n; ++i) {
		double x = (hull[i].x + hull[i+1].x) / 3;
		double tarea = hull[i] * hull[i+1] / 2;
		cx += x * tarea;
		area += tarea;
	}
	cx /= area;

	double l = 1e10, r = -1e10;
	for (int i = 0; i < n; ++i) {
		if (dcmp(hull[i].y) == 0) {
			l = min(l, hull[i].x);
			r = max(r, hull[i].x);
		}
	}
	
	double k1 = target.x - l;
	double k2 = target.x - r;
	double t1 = (l - cx) * area;
	double t2 = (r - cx) * area;

	if (dcmp(k1) < 0 || dcmp(k2) < 0) {
		swap(k1, k2);
		swap(t1, t2);
		k1 *= -1;
		k2 *= -1;
		t1 *= -1;
		t2 *= -1;
	}
	double ansl, ansr;
	if (dcmp(k1) == 0) {
		if (dcmp(t1) <= 0) {
			ansl = 0;
		} else {
			puts("unstable");
			return 0;
		}
	} else {
		ansl = t1 / k1;
	}
	if (dcmp(k2) == 0) {
		if (dcmp(t2) >= 0) {
			ansr = 1e30;
		} else {
			puts("unstable");
			return 0;
		}
	} else ansr = t2 / k2;

	ansl = max(ansl, 0.0);
	if (ansl > ansr) {
		puts("unstable");
		return 0;
	}
	if (ansr > 1e20) {
		printf("%d .. inf\n", (int) ansl);
	} else {
		printf("%d .. %d\n", (int) ansl, (int) ceil(ansr));
	}

	return 0;
}

// hehe ~


