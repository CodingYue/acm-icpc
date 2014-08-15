#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

#define MP make_pair
#define fi first
#define se second

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

struct Point3D {
	double x, y, z;
	Point3D(){}
	Point3D(double x, double y, double z)
		: x(x), y(y), z(z) {}
	Point3D operator + (const Point3D &b) {
		return Point3D(x + b.x, y + b.y, z + b.z);
	}
	Point3D operator - (const Point3D &b) {
		return Point3D(x - b.x, y - b.y, z - b.z);
	}
	double operator * (const Point3D &b) {
		return x * b.y - y * b.x;
	}
	Point3D operator * (const double &b) {
		return Point3D(x * b, y * b, z * b);
	}
	bool operator < (const Point3D &b) const {
		return dcmp(z - b.z) < 0;
	}
};
typedef pair<Point3D, Point3D> Segment;
struct Point {
	double x, y;
	Point(){}
	Point(double x, double y)
		: x(x), y(y) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	double operator * (const Point &b) {
		return x * b.y - y * b.x;
	}
	Point operator * (const double &b) {
		return Point(x * b, y * b);
	}
	bool operator < (const Point &b) const {
		if (dcmp(x-b.x) != 0) return dcmp(x-b.x) < 0;
		return dcmp(y - b.y) < 0;
	}
	bool operator == (const Point &b) const {
		return dcmp(x-b.x) == 0 && dcmp(y-b.y) == 0;
	}
};
double graham(Point *p, int n) {

	sort(p, p + n);
	Point Hull[11];
	int HTop = 0;
	for (int i = 0; i < n; ++i) {
		while (HTop > 1 && dcmp((p[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) --HTop;
		Hull[HTop++] = p[i];
	}
	int LTop = HTop;
	for (int i = n - 2; i >= 0; --i) {
		while (HTop > LTop && dcmp((p[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) --HTop;
		if (i) Hull[HTop++] = p[i];
	}
	
	double area = 0;
	Hull[HTop] = Hull[0];
	for (int i = 0; i < HTop; ++i) {
		area += Hull[i] * Hull[i+1]/2;
	}
	return area;
}

double calc_area(double h1, double h2, double hh, double H) {

	vector<Segment> seg;
	
	Point3D p[3];
	p[0] = Point3D(0, 0, h1);
	p[1] = Point3D(1, 0, h2);
	p[2] = Point3D(0.5, 0.5, hh);
	
	for (int i = 0; i < 3; ++i) {
		Point3D cur = p[i];
		seg.push_back(MP(Point3D(cur.x, cur.y, 0), cur));
	}
	sort(p, p + 3);
	for (int i = 0; i < 3; ++i)
	for (int j = i+1; j < 3; ++j) {
		seg.push_back(MP(p[i], p[j]));
	}
	vector<Point> res;
	for (auto cur : seg) {
		if (dcmp(H - cur.fi.z) < 0 || dcmp(H - cur.se.z) > 0) continue;
		if (dcmp(cur.fi.z - cur.se.z) == 0) {
			res.push_back(Point(cur.fi.x, cur.fi.y));
			res.push_back(Point(cur.se.x, cur.se.y));
		} else {
			Point3D p = cur.fi + (cur.se - cur.fi) * ((H-cur.fi.z)/(cur.se.z-cur.fi.z));
			res.push_back(Point(p.x, p.y));
		}
	}
	
	sort(res.begin(), res.end());
	int n = unique(res.begin(), res.end()) - res.begin();
	Point point[11];
	for (int i = 0; i < n; ++i) point[i] = res[i];
	return graham(point, n);
	
/*
	double h[3] = {h1, h2, hh};
	sort(h, h + 3);
	
	if (dcmp(H) < 0 || dcmp(H - h[2]) > 0) return 0;
	
	if (dcmp(H - h[0]) <= 0) {
		return 1/2.;
	}
	h1 -= h[0];
	h2 -= h[0];
	hh -= h[0];
	H -= h[0];
	if (dcmp(H - h[1]) <= 0) {
		if (dcmp(hh) == 0) {
			
			Point3D v1 = Point3D(0, 0, h1) - Point3D(0.5, 0.5, 0);
			Point3D v2 = Point3D(1, 0, h2) - Point3D(0.5, 0.5, 0);
		
			Point3D p1 = Point3D(0, 0, H);
			Point3D p2 = Point3D(1, 0, H);
		
			v1 = Point3D(0.5, 0.5, 0) + v1 * (H / h1);
			v2 = Point3D(0.5, 0.5, 0) + v2 * (H / h2);
		
			return fabs((v1-v2)*(p1-v2)) + fabs((v2-p1)*(p1-p2));
		} else {
			
			double hx = max(h1, h2);
			
			Point3D v1 = Point3D(0, 0, hh);
			Point3D v2 = Point3D(0, 0, hx);
		
			Point3D p1 = Point3D(0.5, 0.5, H);
			Point3D p2 = Point3D(1, 0, H);
			
			v1 = v1 * (H / hh);
			v2 = v2 * (H / hx);
			
			return fabs((v1-v2)*(p1-v2)) + fabs((v2-p1)*(p1-p2));
		}
	}
	
	h1 = h1 + h[0];
	h2 = h2 + h[0];
	hh = hh + h[0];
	H += h[0];
	
	if (dcmp(hh) > 0) {
		Point3D v1 = Point3D(0.5, 0.5, hh) - Point3D(0, 0, h1);
		Point3D v2 = Point3D(0.5, 0.5, hh) - Point3D(1, 0, h2);
		
		v1 = Point3D(0, 0, h1) + v1 * ((H-h1)/(hh-h1));
		v2 = Point3D(1, 0, h2) + v2 * ((H-h2)/(hh-h2));
		
		Point3D p = Point3D(0.5, 0.5, H);
		return fabs((p-v1)*(p-v2));
	} else {
		
		double hx = max(h1, h2);
		double hm = min(h1, h2);
		
		Point3D v1 = Point3D(0, 0, hx) - Point3D(0.5, 0.5, hh);
		Point3D v2 = Point3D(0, 0, hx) - Point3D(1, 0, hm);
		v1 = Point3D(0.5, 0.5, hh) + v1 * ((H-hh)/(hx-hh));
		v2 = Point3D(1, 0, hm) + v2 * ((H-hh)/(hx-hh));
		
		
		Point3D p = Point3D(0, 0, H);
		return fabs((p-v1)*(p-v2));
	}
	*/
}
double h1, h2, hh;
double f(double x) {
	return calc_area(h1, h2, hh, x);
}
double simpson(double fl, double fr, double fmid, double l, double r) {
	return (fl+fr+4.0*fmid)*(r-l)/6.0;
}
double rsimpson(double slr, double fl, double fr, double fmid, double l, double r) {
	double mid = (l+r)*0.5;
	double fml = f((l+mid)*0.5);
	double fmr = f((mid+r)*0.5);
	double slm = simpson(fl, fmid, fml, l, mid);
	double smr = simpson(fmid, fr, fmr, mid, r);
	if (fabs(slr-slm-smr) < 1e-6) return slm+smr;
	return rsimpson(slm, fl, fmid, fml, l, mid) + rsimpson(smr, fmid, fr, fmr, fmid, r);
}
double getvol(double h) {
	
	double ph[4] = {0, h1, h2, hh};
//	sort(ph + 0, ph + 4);
	sort(ph, ph + 4);
	
	double res = 0.0;
	for (int i = 0; i < 3; ++i) {
		if (dcmp(h-ph[i]) <= 0) break;
		double l = ph[i];
		double r = ph[i+1];
		if (dcmp(l-r) > 0) break;
		if (dcmp(l-r) == 0) continue;
		r = min(r, h);
	
	/*
		double fmid = f((l+r)*0.5);
		double slr = simpson(fl, fr, fmid, l, r);
		
		//double tmp2 = rsimpson(slr, fl, fr, fmid, l, r);
		
		*/
		double fl = f(l);
		double fr = f(r);

//		double tmp1 = 0;
		double tmp1 = 1/3.*(r-l)*(fl+fr+sqrt(fl*fr));
		if (i == 1) {
		
			tmp1 = 1/3.*(fl*2+fr)*(r-l);
			
//		if (fabs(tmp1 - tmp2) > 1e-4) {
//			printf("i = %d, l = %.3f, r = %.3f, h1 = %.3f, h2 = %.3f, hh = %.3f yes = %d\n", i, l, r, h1, h2, hh, fabs(tmp1-tmp2) < 1e-4);
			
			//}
		}
		
		res += tmp1;
	}
	return res;
}
void solve(double H1, double H2, double HH, double H, double &digout, double &pullin) {

	h1 = H1;
	h2 = H2;
	hh = HH;
	
	double allvol = getvol(max(max(h1, h2), hh));
	double volH = getvol(H);	
	digout += allvol - volH;
	pullin -= volH;
}
double h[333][333];
int main() {

	//freopen("Ain","r",stdin);

	int n, m; 
	while (scanf("%d %d", &n, &m) != EOF) {
		
		double H; scanf("%lf", &H);
		
		for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j) scanf("%lf", &h[i][j]);
		
		double digout = 0;
		double pullin = n*m*H;
		
	//	solve(0, 0, 1, 1, digout, pullin);
		
		
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			double x; scanf("%lf", &x);
			
			solve(h[i][j], h[i+1][j], x, H, digout, pullin);
			solve(h[i][j], h[i][j+1], x, H, digout, pullin);
			solve(h[i+1][j], h[i+1][j+1], x, H, digout, pullin);
			solve(h[i][j+1], h[i+1][j+1], x, H, digout, pullin);
		}
		
		printf("%.3f %.3f\n", digout, pullin);
		
	}
	
	return 0;
}
