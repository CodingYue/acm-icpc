#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;
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
	Point rot90(int t = 1) { return Point(-y, x) * t; }
	Point rot(double ang) { return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); }
	double ang() const { double res = atan2(y, x); if (dcmp(res) < 0) res += pi * 2; return res; }
	double operator * (const Point &b) { return x * b.y - y * b.x; }
	double operator % (const Point &b) { return x * b.x + y * b.y; }
	double len2() { return x * x + y * y; }
	double len() { return sqrt(x * x + y * y); }
	void init() { scanf("%lf %lf", &x, &y); }
	bool operator < (const Point &b) const {
		if (dcmp(x - b.x) != 0) return dcmp(x-b.x) < 0;
		return dcmp(y - b.y) < 0;
	}
	bool operator == (const Point &b) const {
		return dcmp(x-b.x) == 0 && dcmp(y-b.y) == 0;
	}
};
double R;
double dis_p_seg(Point q, Point p1, Point p2) {
	double dis = fabs((p1 - q) * (p2 - q)) / (p1 - p2).len();
	if (dcmp((q - p1) % (p2 - p1)) > 0 && dcmp((q - p2) % (p1 - p2)) > 0) return dis;
	return min((q - p1).len(), (q - p2).len());
}

typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<Point, int> ppi;
struct Line {
	Point s, e;
	Line(){}
	Line(Point s, Point e) : s(s), e(e) {}
};
vector<Line> getLineCC(Point c1, double r1, Point c2, double r2) {
	vector<Line> res;
	double d = (c1 - c2).len();
	if (fabs(d - r1 - r2) < eps) {
		Point o = (c1 + c2) * 0.5;
		res.push_back(Line(o, o + (c1 - c2).rot90()));
		res.push_back(res[res.size() - 1]);
	} else {
		double ang = acos((r1 + r2) / d);
		res.push_back(Line(c1 + ((c2 - c1) * (r1 / d)).rot(ang), c2 + ((c1 - c2) * (r2 / d)).rot(ang)));
		ang = -ang;
		res.push_back(Line(c1 + ((c2 - c1) * (r1 / d)).rot(ang), c2 + ((c1 - c2) * (r2 / d)).rot(ang)));
	}
	double ang = acos((r2 - r1) / d);
	res.push_back(Line(c1 + ((c1 - c2) * (r1 / d)).rot(ang), c2 + ((c1 - c2).rot(ang) * (r2 / d))));
	ang = -ang;
	res.push_back(Line(c1 + ((c1 - c2) * (r1 / d)).rot(ang), c2 + ((c1 - c2).rot(ang) * (r2 / d))));
	return res;
}
bool is_point_on_circle(Point p, Point c, double r) {
	return dcmp((p-c).len() - r) == 0;
}
vector<Line> getLinePC(Point c, double r, Point p) {
	vector<Line> res;
	double d = (p-c).len();
	if (dcmp(d-r) <= 0) return res;
	double ang = asin(r/d);
	Point v = (c-p) * (sqrt(d*d-r*r)/d);
	res.push_back(Line(p, p + v.rot(ang)));
	res.push_back(Line(p, p + v.rot(-ang)));
	assert(is_point_on_circle(res[0].e, c, r));
	assert(is_point_on_circle(res[1].e, c, r));
	return res;
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
	Point q2 = ((c2 - c1) * sqrt(d)).rot90();
	res.push_back(q1 - q2);
	res.push_back(q1 + q2);
	return res;
}

int tot;
vector<pid> edges[2333333];
vector<pid> contains[23333];
Point point[23];
bool cmp_angle(const pid &a, const pid &b) {
	if (dcmp(a.second - b.second) != 0) return dcmp(a.second - b.second) < 0;
	int t1 = a.first < 0 ? -1 : 1;
	int t2 = b.first < 0 ? -1 : 1;
	if (t1 != t2) {
		return t1 == -1;
	}
	return a.first > b.first;
}
double dist[233333];
bool vis[2333];
double spfa(int s, int t, int tot) {

	for (int i = 0; i < tot; ++i) dist[i] = 1e30;
	dist[s] = 0;
	set<pair<double, int> > heap;
	heap.insert(pdi(dist[s], s));
	
	while (!heap.empty()) {
	
		pdi cur = *heap.begin(); heap.erase(heap.begin());
		
		if (vis[cur.second]) continue;
		vis[cur.second] = true;
		for (auto &v : edges[cur.second]) {
			if (dist[v.first] > dist[cur.second] + v.second) {
				dist[v.first] = dist[cur.second] + v.second;
				heap.insert(pdi(dist[v.first], v.first));
			}
		}
	}
	return dist[t];
}
int n;
bool check(Point p1, Point p2) {
	for (int i = 0; i < n; ++i) {
//		double dis = fabs((p1-point[i])*(p2-point[i])) / (p1-p2).len();
		double mindis = dis_p_seg(point[i], p1, p2);
		if (dcmp(mindis - R) < 0) return false;
	}
	return true;
}
bool add_point(map<Point, int> &MAP, Point *invMAP, Point p) {

	for (int i = 0; i < n; ++i) {
		if (dcmp((p-point[i]).len() - R) < 0) return false;
	}

	if (MAP.count(p)) return true;
	MAP[p] = tot;
	edges[tot].clear();
	invMAP[tot++] = p;
	return true;
}
Point invMAP[233333];
int main(void) {

	
	while (scanf("%d", &n) != EOF) {
		R = 100.0;
		map<Point, int> MAP;
		
		tot = 0;
		
		Point goal; goal.init();
		Point orin = Point(0, 0);

		
		for (int i = 0; i < n; ++i) {
			contains[i].clear();
			point[i].init();
		}
		bool yes = true;
		yes &= add_point(MAP, invMAP, orin);
		yes &= add_point(MAP, invMAP, goal);
		
		if (!yes) {
			puts("0.0");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			vector<Line> res = getLinePC(point[i], R, orin);
			for (auto &x : res) {
				add_point(MAP, invMAP, x.s);
				add_point(MAP, invMAP, x.e);
			}
			res = getLinePC(point[i], R, goal);
			for (auto &x : res) {
				add_point(MAP, invMAP, x.s);
				add_point(MAP, invMAP, x.e);
			}
			
		}	
		
	
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j) {
			vector<Line> res = getLineCC(point[i], R, point[j], R);
			for (auto &x : res) {
				add_point(MAP, invMAP, x.s);
				add_point(MAP, invMAP, x.e);
			}
		}
		
		for (int i = 0; i < tot; ++i)
		for (int j = 0; j < i; ++j) {
			
			if (check(invMAP[i], invMAP[j])) {
				double dis = (invMAP[i] - invMAP[j]).len();
				edges[i].push_back(pid(j, dis));
				edges[j].push_back(pid(i, dis));
			}
			
		}

		for (int x = 0; x < n; ++x) {
			for (int i = 0; i < tot; ++i) {
				if (!is_point_on_circle(invMAP[i], point[x], R)) continue;
				contains[x].push_back(pid(i+10, (invMAP[i] - point[x]).ang()));
			}
			sort(contains[x].begin(), contains[x].end(), cmp_angle);
		}
		
		for (int i = 0; i < n; ++i) {
			if (contains[i].size() == 0) continue;
			vector<pid> events;
			for (auto &x : contains[i]) events.push_back(x);
			events.push_back(pid(contains[i][0].first, contains[i][0].second+2*pi));
			for (int j = 0; j < n; ++j) if (i != j) {
			
				vector<Point> res = getCC(point[i], R, point[j], R);
				if (res.size() < 2) continue;
			
				double ang1 = (res[0]-point[i]).ang();
				double ang2 = (res[1]-point[i]).ang();
				
				if (dcmp(ang1-ang2) == 0) continue;
				if (dcmp(ang1-ang2) > 0) {
					events.push_back(pid(-1, ang2));
					events.push_back(pid(1, 0.0));
					events.push_back(pid(1, ang1));
					events.push_back(pid(-1, ang2+2*pi));
				} else {
					events.push_back(pid(1, ang1));
					events.push_back(pid(-1, ang2));
					events.push_back(pid(1, ang1+2*pi));
					events.push_back(pid(-1, ang2+2*pi));
				}
			}
			sort(events.begin(), events.end(), cmp_angle);
/*			for (auto &x : events) {
				printf("%.8f ", x.second);
			}
			puts("");
	*/
			int cnt = 0;
			int pre = -1;
			double pre_ang = 0;
			for (auto &x : events) {
			
				if (x.first >= 10) {
					if (pre != -1 && cnt == 0) {
						double ang = x.second - pre_ang;
						if (dcmp(ang - 2*pi) > 0) {
							ang -= 2*pi;
						}
						double dis = ang * R;
//						if (dcmp(dis - 2*pi) > 0) dis -= 2*pi;
						edges[x.first-10].push_back(pid(pre, dis));
						edges[pre].push_back(pid(x.first-10, dis));
					}
					if (cnt == 0) {
						pre = x.first-10;
						pre_ang = x.second;
					}
				} else {
					cnt += x.first;
					if (cnt > 0) {
						pre = -1;
					}
				}
			
			}
		}
/*
		for (int i = 0; i < tot; ++i) {
			for (auto &v : edges[i]) {
				printf("%d --> %d %.10f\n", i, v.first, v.second);
			}
		}
	*/

		double ans = spfa(MAP[orin], MAP[goal], tot);
		if (ans < 1e10) printf("%.10f\n", ans);
		else puts("0.0");		
	}
	

	return 0;
}

