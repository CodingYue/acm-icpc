// File Name: 10173.cpp
// Author: YangYue
// Created Time: Fri Oct 10 11:32:27 2014
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
struct Point {
	double x, y;
	Point(){}
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (const Point &b) { return Point(x+b.x, y+b.y); }
	Point operator - (const Point &b) { return Point(x-b.x, y-b.y); }
	Point operator * (const double &b) { return Point(x*b, y*b); }
	Point operator / (const double &b) { return Point(x/b, y/b); }
	double operator * (const Point &b) { return x*b.y-y*b.x; }
	double operator % (const Point &b) { return x*b.x+y*b.y; }
	void init() {
		scanf("%lf %lf", &x, &y);
	}
	double len() {
		return sqrt(x*x + y*y); 
	}
	bool operator < (const Point &b) const {
		if (dcmp(x-b.x) != 0) return dcmp(x-b.x) < 0;
		return dcmp(y-b.y) < 0;
	}
} point[MaxN], hull[MaxN];
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
double getminarea(Point *p, int n) {
	p[n] = p[0];
	int l = 0, up = 0, dn = 0;
	double best = 0;
	for (int i = 0; i < n; ++i) {
		double tmp = (p[i] - p[0]) % (p[1] - p[0]);
		if (best > tmp) {
			best = tmp;
			dn = i;
		}
	}
	double res = 1e30;
	for (int i = 0; i < n; ++i) {
		Point v = (p[i+1]-p[i]);
		while (dcmp((p[up]-p[i]) % v - (p[up+1]-p[i]) % v) <= 0) up = (up+1) % n;
		while (dcmp((p[dn]-p[i]) % v - (p[dn+1]-p[i]) % v) >= 0) dn = (dn+1) % n;
		while (dcmp(fabs((p[l]-p[i]) * v) - fabs((p[l+1]-p[i]) * v)) <= 0) l = (l+1) % n;
		double t1 = fabs((p[up] - p[i]) % (p[i+1] - p[i])) / (p[i+1] - p[i]).len();
		double t2 = fabs((p[dn] - p[i]) % (p[i+1] - p[i])) / (p[i+1] - p[i]).len();
		double t3 = fabs((p[l] - p[i]) * (p[i+1] - p[i])) / (p[i+1] - p[i]).len();
		res = min(res, (t1 + t2) * t3);
	}
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	int n;
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) point[i].init();
		n = Graham(point, hull, n);
		if (n < 3) {
			puts("0.0000");
			continue;
		}
		printf("%.4f\n", getminarea(hull, n));
	}
	
	return 0;
}

// hehe ~


