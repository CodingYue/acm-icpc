// File Name: E.cpp
// Author: YangYue
// Created Time: Tue Apr 22 21:48:50 2014
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

const int MaxN = 4000005;
const double eps = 1e-11;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = acos(-1.0);

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}
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
	double ang() { double res = atan2(y, x); if (dcmp(res) < 0) res += pi * 2; return res; }
	double operator * (const Point &b) { return x * b.y - y * b.x; }
	double operator % (const Point &b) { return x * b.x + y * b.y; }
	double len2() { return x * x + y * y; }
	double len() { return sqrt(x * x + y * y); }
};
vector<Point> getCC(Point c1, double r1, Point c2, double r2) { 
	vector<Point> res;
	double x = (c1 - c2).len2();
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if (d < -eps) return res;
	if (d < 0) d = 0;
	Point q1 = c1 + (c2 - c1) * y;
	Point q2 = ((c2 - c1) * sqrt(d)).rot90(1);
	res.push_back(q1 - q2);
	res.push_back(q1 + q2);
	return res;
}
struct Interver {
	double pos;
	int d;
	Interver(){}
	Interver(double pos, int d) : pos(pos), d(d) {}
	bool operator < (const Interver &b) const {
		if (dcmp(pos - b.pos) == 0) return d > b.d;
		return pos < b.pos;
	}
} interver[MaxN];
int m;
void check(Point c1, double d, Point c2, double r2) {
	int up = ((c1 - c2).len() - r2) / d;
	for (int i = -2; i < 50; ++i) if (up + i >= 1) {
		vector<Point> inter = getCC(c1, d * (up + i), c2, r2);
		if (inter.size() == 0) continue;
		double ang1 = inter[0].ang();
		double ang2 = inter[1].ang();
		if (dcmp(ang1 - ang2) > 0) {
			interver[m++] = Interver(0, 1);
			interver[m++] = Interver(ang2, -1);
			interver[m++] = Interver(ang1, 1);
			interver[m++] = Interver(2 * pi, -1);
		} else {
			interver[m++] = Interver(ang1, 1);
			interver[m++] = Interver(ang2, -1);
		}
	}
}
int main()
{
//	freopen("in","r",stdin);

	int n;
	double d;
	scanf("%d %lf", &n, &d);
	for (int i = 0; i < n; ++i) {
		double x, y, r; scanf("%lf %lf %lf", &x, &y, &r);
		check(Point(0, 0), d, Point(x, y), r);
	}
	sort(interver, interver + m);
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < m; ++i) {
		cnt += interver[i].d;
		res = max(res, cnt);
	}
	printf("%d\n",res);
	
	return 0;
}

// hehe ~


