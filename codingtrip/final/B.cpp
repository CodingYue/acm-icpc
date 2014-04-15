// File Name: B.cpp
// Author: YangYue
// Created Time: Mon Apr 14 19:08:49 2014
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
int dcmp(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
	double x, y;
	Point (){}
	Point(double x, double y) : x(x), y(y) {}
	Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
	Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
	Point operator * (const double &b) { return Point(x * b, y * b); }
	Point operator / (const double &b) { return Point(x / b, y / b); }
	Point rot90(int t) { return Point(-y, x) * t; }
	Point rot(double ang) { return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); }
	double operator * (const Point &b) { return x * b.y - y * b.x; }
	double operator % (const Point &b) { return x * b.x + y * b.y; }
	double len2() { return x * x + y * y; }
	double len() { return sqrt(x * x + y * y); }
	void init() { scanf("%lf%lf", &x, &y); }
	bool operator < (const Point &b) const {
		if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
		return dcmp(y - b.y) < 0;
	}
	Point normalize() {
		double L = this->len();
		return Point(x / L, y / L);
	}
	bool operator == (const Point &b) const { return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0; }
} p[MaxN], hull[MaxN];
int Graham(Point* P,Point* Hull,int n)
{
	sort(P,P+n);
	int HTop = 0;
	for(int i = 0;i < n;i++)
	{
		// delete collinear points
		while(HTop > 1 && dcmp((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) HTop--;
		Hull[HTop++] = P[i];
	}
	int LTop = HTop;
	for(int i = n-2;i >= 0;i--)
	{
		while(HTop > LTop && dcmp((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) HTop--;
		if(i) Hull[HTop++] = P[i];
	}
	return HTop;
}
double cross(Point a, Point b) {
	return a * b;
}
double min_per(Point *p, int n) {
	double res = 1e10;
	int l = 1, r = 1, u = 1;
	p[n] = p[0];
	for (int i = 0; i < n; ++i) {
		Point edge = (p[i+1] - p[i]).normalize();

		while (dcmp(edge % (p[r%n] - p[i]) - edge % (p[(r+1)%n] - p[i])) < 0) ++r;
		while( u < r || edge * (p[u%n]-p[i]) < edge * (p[(u+1)%n]-p[i]) )	u++;
		while( l < u || edge % (p[l%n]-p[i]) > edge % (p[(l+1)%n]-p[i]) )	l++;
		double w = edge % (p[r%n]-p[i]) - edge % (p[l%n]-p[i]);
		double h = fabs(cross(p[i]-p[u%n], p[(i+1)%n]-p[u%n]) / (p[i] - p[(i+1)%n]).len());
		res = min(res, (w + h) * 2);
	}
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) p[i].init();
		n = Graham(p, hull, n);
		double res = min_per(hull, n);
		printf("%.6f\n", res);
	}

	return 0;
}

// hehe ~


