#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

struct Point {
	double x, y;
	Point(){}
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &b) {
		return Point(x * b, y * b);
	}
	Point operator / (const double &b) {
		return Point(x / b, y / b);
	}
	double operator * (const Point &b) {
		return x * b.y - y * b.x;
	}
	double operator % (const Point &b) {
		return x * b.x + y * b.y;
	}
	double len() {
		return sqrt(x * x + y * y);
	}
	double len2() {
		return x * x + y * y;
	}
	void init() {
		scanf("%lf %lf", &x, &y);
	}
	bool operator == (const Point &b) const {
		return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
	}
	Point rot90() {
		return Point(-y, x);
	}
} p[205];

int n;
bool in(Point q) {
	p[n] = p[0];
	bool find = 0;
	for (int i = 0; i < n; ++i) {
		if (dcmp((p[i] - q) * (p[i+1] - q)) < 0) {
			find = 1;
		}
		if (dcmp((p[i] - q) * (p[i+1] - q)) == 0) return false;
	}
	if (find) return false;
	return true;
}
bool cover(Point o, double r, Point p) {
	return dcmp((p-o).len() - r) <= 0;
}
vector<Point> getCC(Point c1, double r1, Point c2, double r2) {
	vector<Point> res;
	double x = (c1 - c2).len2();
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if (d < -eps) return res;
	if (d < 0) d = 0;
	Point q1 = c1 + (c2 - c1) * y;
	Point q2 = ((c2 - c1) * sqrt(d)).rot90();
	res.push_back(q1 - q2);
	res.push_back(q1 + q2);
	return res;
}
bool check(double r, Point o1, Point o2) {
	for (int i = 0; i < n; ++i) {
		if (!(cover(o1, r, p[i]) || cover(o2, r, p[i]))) return false;
	}
	if (o1 == o2) return true;
	vector<Point> interp = getCC(o1, r, o2, r);
	for (int i = 0; i < interp.size(); ++i)
		if (in(interp[i])) return false;
	return true;
}
int main() {
//	freopen("Jin","r",stdin);

	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) p[i].init();
	Point o1, o2; o1.init(); o2.init();
	
	double l = 0.0, r = 1e10;
	for (int TT = 0; TT < 100; ++TT) {
		double mid = (l + r) / 2;
		if (check(mid, o1, o2)) r = mid; else l = mid;
	}

	printf("%.3f\n", r);

	return 0;
