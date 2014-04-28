// File Name: 2B.cpp
// Author: YangYue
// Created Time: Sat Apr 26 15:57:18 2014
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
double pi = acos(- 1.0);
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
	void init() {
		scanf("%lf %lf", &x, &y);
	}
};
// 直线与圆的交点
Point getCL(Point c, double r, Point p1, Point p2) { 
	double x = (p1 - c) % (p2 - p1);
	double y = (p2 - p1).len2();
	double d = x * x - y * ((p1 - c).len2() - r * r);
	if (d < 0) d = 0;
	Point q1 = p1 - ((p2 - p1) * (x / y));
	Point q2 = (p2 - p1) * (sqrt(d) / y);
	if (dcmp((q1 - q2 - p1) % (p2 - p1)) > 0) return q1 - q2;
	else return q1 + q2;
}
// 圆与圆的交点
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
pair<double, int> interval[MaxN];
int m = 0;
void add(Point p1, Point p2) {
	double ang1 = p1.ang();
	double ang2 = p2.ang();
	if (dcmp(ang1 - ang2) == 0) return;
	if (ang1 > ang2) {
		interval[m++] = MP(0, 1);
		interval[m++] = MP(ang2, -1);
		interval[m++] = MP(ang1, 1);
		interval[m++] = MP(2 * pi, -1);
	} else {
		interval[m++] = MP(ang1, 1);
		interval[m++] = MP(ang2, -1);
	}
}
int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case %d: ", ++cas);
		double R, H;
		scanf("%lf %lf", &R, &H);
		int n; scanf("%d", &n);
		m = 0;
		for (int i = 0; i < n; ++i) {
			Point c; double r, h;
			c.init(); scanf("%lf %lf", &r, &h);
			if (dcmp(h - H) >= 0) {
				Point vect = c / c.len();
				double ang = asin(r / c.len());
				double len = sqrt(c.len2() - r * r);
				Point p2 = vect.rot(ang) * len;
				Point p1 = vect.rot(-ang) * len;
				add(p1, p2);
			} else {
				c = c * (H / (H - h));
				r = r * (H / (H - h));
				Point vect = c / c.len();
				double ang = asin(r / c.len());
				double len = sqrt(c.len2() - r * r);
				Point p2 = vect.rot(ang) * len;
				Point p1 = vect.rot(-ang) * len;
				if (dcmp(p1.len2() - R * R) >= 0) {
					add(p1, p2);
				}
				vector<Point> res = getCC(Point(0, 0), R, c, r);
				if (res.size() == 0) continue;
				add(res[0], res[1]);
			}
		}
		sort(interval, interval + m);
		int cnt = 0;
		double res = 0;
		for (int i = 0; i < m; ++i) {
			if (cnt > 0) res += (interval[i].first - interval[i-1].first);
			cnt += interval[i].second;
		}
		printf("%.10f\n", 1 - res / (2 * pi));
	}
	
	return 0;
}

// hehe ~


