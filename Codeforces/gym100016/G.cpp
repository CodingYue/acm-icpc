// File Name: G.cpp
// Author: YangYue
// Created Time: Wed Jul  2 11:33:20 2014
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
const double eps = 1e-13;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = acos(-1.0);

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}
int n, m;
struct Point {
	double x, y, z;
	Point(){}
	Point(double x, double y, double z) :
		x(x), y(y), z(z) {}
	Point operator + (const Point &b) { return Point(x + b.x, y + b.y, z + b.z); }
	Point operator - (const Point &b) { return Point(x - b.x, y - b.y, z - b.z); }
	Point operator * (const Point &b) {
		double aa = y * b.z - z * b.y;
		double bb = z * b.x - x * b.z;
		double cc = x * b.y - y * b.x;
		return Point(aa, bb, cc);
	}
	double operator % (const Point &b) { return x * b.x + y * b.y + z * b.z; }
	double len() { return sqrt(x * x + y * y + z * z); }
	Point operator * (const double &b) { return Point(x * b, y * b, z * b); }
	Point operator / (const double &b) { return Point(x / b, y / b, z / b); }
	void init() { scanf("%lf %lf %lf", &x, &y, &z); }
	bool operator < (const Point &b) const {
		if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
		if (dcmp(y - b.y) != 0) return dcmp(y - b.y) < 0;
		return dcmp(z - b.z) < 0;
	}
	bool operator == (const Point &b) const {
		if (dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0 && dcmp(z - b.z) == 0) return true;
		return false;
	}
} Plane[MaxN], p[MaxN];
int pp[MaxN];
double get_angle(Point p1, Point p2) {
	double res = p1 % p2;
	res = res / p1.len() / p2.len();
	return fabs(acos(res));
}
vector<Point> getFF(Point p1, Point o1, Point p2, Point o2) {
	vector<Point> res;
	Point e = o1 * o2;
	Point v = o1 * e;
	double d = o2 % v;
	if (fabs(d) < eps) return res;
	Point q = p1 + v * ((o2 % (p2 - p1)) / d);
	res.push_back(q);
	res.push_back(q + e);
	return res;
}
int total;
map<Point, int> MAP;
Point point[MaxN];
vector<int> edges[MaxN];
void add(int a, int b) {
	edges[a].push_back(b);
}
int count(Point p) {
	if (!MAP.count(p)) {
		point[total] = p;
		MAP[p] = total++;
	}
	return MAP[p];
}
double calc(Point a, Point b, Point c) {
	double res = -pi;
	Point s1 = a * b;
	Point s2 = b * c;
	Point s3 = c * a;
	res += pi - get_angle(s1, s2);
	res += pi - get_angle(s2, s3);
	res += pi - get_angle(s1, s3);
	return fabs(res);
}
set<PII> vis;
double dist(PDD p) {
	return sqrt(p.first * p.first + p.second * p.second);
}
vector<int> now;
double dfs(int u, int pre, int source) {
	now.push_back(u);
	int m = 0;
	double res = 0.0;
	for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) if (!vis.count(MP(u, *it))) {
		p[m++] = point[*it] - point[u];
	}
	if (pre == -1) return res;
	Point s = point[u];
	Point e1 = Point(0, -s.z, s.y);
	if (e1 == Point(0, 0, 0)) {
		e1 = Point(0, 1, 1);
	}
	Point e2 = s * e1;
	s = s / s.len();
	e1 = e1 / e1.len();
	e2 = e2 / e2.len();
	PDD from = MP((point[pre] - point[u]) % e1, (point[pre] - point[u]) % e2);
	int best = -1;
	double Max = -1111;
	for (int i = 0; i < m; ++i) {
		PDD cur = MP(e1 % p[i], e2 % p[i]);
		double tmp = from.first * cur.second - from.second * cur.first;
		if (dcmp(tmp) >= 0) continue;
		tmp = from.first * cur.first + from.second * cur.second;
		tmp = tmp / dist(from) / dist(cur);
		if (tmp > Max) {
			best = i;
			Max = tmp;
		}
	}
	if (best == -1) return -1;
	int next = MAP[point[u] + p[best]];
	vis.insert(MP(u, next));
	if (next == source) return 0;
	double tmp = dfs(next, u, source);
	if (tmp == -1) return -1;
	return tmp + calc(point[source], point[u], point[next]);
}
double ang[111111];
bool cmp(const int &a, const int &b) {
	return ang[a] < ang[b];
}
int main()
{
	freopen("orange.in","r",stdin);
	//freopen("out","w",stdout);

	double r;
	scanf("%lf %d", &r, &n);
	
	for (int i = 0; i < n; ++i) {
		Plane[i].init();
	}
	if (n == 1) {
		printf("2\n");
		for (int i = 0; i < 2; ++i)
			printf("%.10f\n", pi * 2 / 3 * r * r * r);
		return 0;
	}
	Point origin = Point(0, 0, 0);
	for (int i = 0; i < n; ++i) {
		int m = 0;
		for (int j = 0; j < n; ++j) if (i != j) {
			vector<Point> vect = getFF(origin, Plane[i], origin, Plane[j]);
			Point p1 = (vect[1] - vect[0]);
			Point p2 = p1 * -1;
			p1 = p1 / p1.len();
			p2 = p2 / p2.len();
			int n1 = count(p1), n2 = count(p2);
			pp[m++] = n1;
			pp[m++] = n2;
		}
		sort(pp, pp + m); m = unique(pp, pp + m) - pp;
		Point e1 = Point(0, - Plane[i].z, Plane[i].y);
		if (e1 == Point(0, 0, 0)) {
			e1 = Point(0, 0, 1);
		}
		Point e2 = Plane[i] * e1;
		e1 = e1 / e1.len();
		e2 = e2 / e2.len();
		for (int i = 0; i < m; ++i) {
			double x = point[pp[i]] % e1;
			double y = point[pp[i]] % e2;
			ang[pp[i]] = atan2(y, x);
		}
		sort(pp, pp + m, cmp);
		/*
		for (int i = 0; i < m; ++i) {
			int k = pp[i];
			printf("%d %.3f ", k, ang[k]);
		}
		printf("\n");
		*/
		for (int i = 0; i < m; ++i) {
			add(pp[i], pp[(i+1)%m]);
			add(pp[(i+1)%m], pp[i]);
		}
	}
	vector<double> res;
	if (total == 2) {
		Point s = point[0] - point[1];
		Point e1 = Point(0, -s.z, s.y);
		if (e1 == Point(0, 0, 0)) {
			e1 = Point(0, 1, 0);
		}
		Point e2 = s * e1;
		e1 = e1 / e1.len();
		e2 = e2 / e2.len();
		for (int i = 0; i < n; ++i) {
			double x = Plane[i] % e1;
			double y = Plane[i] % e2;
			ang[i] = atan2(y, x);
			ang[i + n] = atan2(-y, -x);
		}
		sort(ang, ang + n * 2);
		ang[n*2] = ang[0] + 2 * pi;
		for (int i = 0; i < n * 2; ++i) {
			res.push_back(fabs(ang[(i+1)] - ang[i]) * 2 * r * r * r / 3);
		}
		sort(res.begin(), res.end());
		printf("%d\n", res.size());
		for (int i = 0; i < (int) res.size(); ++i) printf("%.10f\n", res[i]);
		return 0;
	}
	/*
	for (int i = 0; i < total; ++i) {
		printf("cnt = %d %.3f %.3f %.3f\n", i, point[i].x, point[i].y, point[i].z);
	}
	*/
	for (int i = 0; i < total; ++i) {
		for (vector<int> :: iterator it = edges[i].begin(); it != edges[i].end(); ++it) if (!vis.count(MP(i, *it))) {
			vis.insert(MP(i, *it));
			now.clear();
			now.push_back(i);
			double angle = dfs(*it, i, i);
			res.push_back(angle*r*r*r/3);
			/*
			printf("%.10f\n", angle);
			angle = 0;
			for (int i = 0; i < (int) now.size(); ++i) {
				int j = (i + 1) % now.size();
				int k = (j + 1) % now.size();
				Point p1 = point[now[i]] * point[now[j]];
				Point p2 = point[now[k]] * point[now[j]];
				double ppp = p1 % p2;
				ppp = ppp / p1.len() / p2.len();
				angle += acos(ppp);
			}
			angle -= (now.size() - 2) * pi;
			res.push_back(angle * r * r * r / 3);
			*/
		}
	}
	sort(res.begin(), res.end());
	//cerr << res.size() << endl;
	printf("%d\n", res.size());
	for (int i = 0; i < (int) res.size(); ++i) printf("%.10f\n", res[i]);
	
	return 0;
}

// hehe ~




