// File Name: L.cpp
// Author: YangYue
// Created Time: Thu Jul  3 15:54:34 2014
//headers 
#include <cstdio>
#include <assert.h>
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

const int MaxN = 100005;
const double eps = 1e-13;
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
	Point(double x, double y)
		: x(x), y(y) {}
	double operator * (const Point &b) const {
		return x * b.y - b.x * y;
	}
	double operator % (const Point &b) const {
		return x * b.x + y * b.y;
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	bool operator < (const Point &b) const {
		int t = dcmp(x - b.x);
		if (t != 0) return t < 0;
		return dcmp(y - b.y) < 0;
	}
	bool operator == (const Point &b) const {
		return dcmp(x - b.x) == 0 && dcmp(y - b.y) ==0;
	}
	double len() {
		return sqrt(x * x + y * y); 
	}
	void init() {
		scanf("%lf %lf", &x, &y);
	}
} point[MaxN], que[33333];
struct Segment {
	Point s, e;
	Segment(){}
	Segment(Point s, Point e) : s(s), e(e) {}
	bool operator < (const Segment &b) const {
		if (s == b.s) return e < b.e;
		return s < b.s;
	}
}segment[3333];
vector<Segment> interval[3333];
bool hide[3333];
double xmul(Point a, Point b, Point c) {
	return (b - a) * (c - a);
}
Point get_intersect(Segment s1, Segment s2) { 
	double u = xmul(s1.s, s1.e, s2.s);
	double v = xmul(s1.e, s1.s, s2.e);
	Point t;
	t.x = (s2.s.x * v + s2.e.x * u) / (u + v);
	t.y = (s2.s.y * v + s2.e.y * u) / (u + v);
	return t;
}
int total = 0;
map<Point, int> MAP;
int count(Point p) {
	if (!MAP.count(p)) {
		point[total] = p;
		MAP[p] = total++;
	}
	return MAP[p];
}
vector<int> edges[MaxN];
vector<int> list;
set<PII> vis;
map<PII, int> belong;
map<PII, int> weight;
bool dfs(int u, int pre, int fir) {
	if (u == fir) return 1;
	list.push_back(u);
	Point v1 = point[pre] - point[u];
	int next = -1;
	Point choose = Point(0, 0);
	for (int v : edges[u]) if (v != pre) {
		Point v2 = point[v] - point[u];
		if (dcmp(v2 * v1) > 0) {
			if (next == -1 || dcmp(v2 * choose) < 0) {
				choose = v2;
				next = v;
			}
		}
	}
	if (next == -1) return false;
	//if (pre == next) while(1);
	vis.insert(MP(u, next));
	return dfs(next, u, fir);
}
int area = 0;
int point_location(Point p, int label) {
	int n = list.size() - 1;
	for (int k = 0; k < n; ++k) {
		int a = list[k];
		int b = list[k+1];
		if (dcmp(xmul(p, point[a], point[b])) < 0) {
			return 0;
		}
	}
	return label;
}
vector<PII> gragh[MaxN];
priority_queue<PII> heap;
int dist[MaxN];
int dijkstra(int source, int sink) {
	for (int i = 0; i <= area; ++i) dist[i] = INF;
	dist[source] = 0;
	heap.push(MP(0, source));
	while (!heap.empty()) {
		while (!heap.empty() && dist[heap.top().second] != - heap.top().first) {
			heap.pop();
		}
		if (heap.empty()) break;
		int u = heap.top().second;
		heap.pop();
		for (PII p : gragh[u]) {
			int v = p.first;
			int w = p.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				heap.push(MP(-dist[v], v));
			}
		}
	}
	return dist[sink];
}
bool is_segment_same(Segment s1, Segment s2) {
	double u = xmul(s1.s, s1.e, s2.s);
	double v = xmul(s1.e, s1.s, s2.e);
	if (dcmp(u) == 0 && dcmp(v) == 0) return true;
	return false;
}
bool is_contains(Segment s1, Segment s2) {

	if (s2.s < s1.s) return false;
	if (s1.e < s2.e) return false;
	return true;
}
bool parallel(Segment s1, Segment s2) {
	return dcmp((s1.e - s1.s) * (s2.e - s2.s)) == 0;
}
bool cmp(const int &a, const int &b) {
	return point[a] < point[b];
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	Point source, sink;
	source.init(); sink.init();
	for (int i = 0; i < n; ++i) {
		Point s, e;
		s.init(); e.init();
		if (e < s) swap(s, e);
		segment[i] = Segment(s, e);
	}
	sort(segment, segment + n);
	for (int i = 0; i < n; ++i) if (!hide[i]) {
		interval[i].push_back(segment[i]);
		for (int j = i + 1; j < n; ++j) if (!hide[j] && is_segment_same(segment[i], segment[j])) {
			hide[j] = 1;
			if (segment[j].s == interval[i][interval[i].size() - 1].e) {
				interval[i][interval[i].size() - 1].e = segment[j].e;
			} else {
				interval[i].push_back(segment[j]);
			}
		}
	}
	//for (Segment p : interval[1]) printf("%.3f %.3f\n", p.s.x, p.s.y);
	vector<int> que;
	for (int i = 0; i < n; ++i) if (!hide[i]) {
		que.clear();
		for (int j = 0; j < n; ++j) if (i != j && !hide[j]) {
			if (parallel(segment[i], segment[j])) continue;
			Point p = get_intersect(segment[i], segment[j]);
			que.push_back(count(p));
		}
		sort(que.begin(), que.end(), cmp); 
		int m = unique(que.begin(), que.end()) - que.begin();
		//vector<Segment> :: iterator cur = interval[i].begin();
		for (int k = 0; k < m - 1; ++k) {
			int a = que[k];
			int b = que[k+1];
			edges[a].push_back(b);
			edges[b].push_back(a);
			//              printf("%d\n", cur == interval[i].end());
			//while (cur != interval[i].end() && cur->e < que[k]) ++cur;
			//              printf("%d\n", cur == interval[i].end());
			for (vector<Segment> :: iterator cur = interval[i].begin(); cur != interval[i].end(); ++cur)
				if (is_contains(*cur, Segment(point[que[k]], point[que[k+1]]))) weight[MP(a, b)] = weight[MP(b, a)] = 1;
		}
	}
	int s = 0;
	int t = 0;
	for (int u = 0; u < total; ++u) {
		for (int v : edges[u]) if (!vis.count(MP(u, v))) {
			vis.insert(MP(u, v));
			list.clear();
			list.push_back(u);

			bool can = dfs(v, u, u);
			//      for (int x : list) printf("%d ", x); printf("\n");
			if (can) {
				//              if (list.size() < 3) while(1);
				++area;
				list.push_back(list[0]);
				if (s == 0) s = point_location(source, area);
				if (t == 0) t = point_location(sink, area);
				for (int i = 0; i < (int) list.size() - 1; ++i) {
					//      assert(!belong.count(MP(list[i], list[i+1])));
					//      assert(!belong.count(MP(list[i+1], list[i])) || belong[MP(list[i+1], list[i])] != area);
					belong[MP(list[i], list[i+1])] = area;
				}

				/*
				   for (int x = 0; x < (int) list.size() - 1; ++x)
				   for (int y = 0; y < (int) list.size() - 1; ++y) 
				   assert(MP(list[x], list[x+1]) != MP(list[y+1], list[y]));
				   */

			} else {
				for (int i = 0; i < (int) list.size() - 1; ++i) {
					belong[MP(list[i], list[i+1])] = 0;
				}
			}
		}
	}
	for (int u = 0; u < total; ++u) {
		for (int v : edges[u]) {
			//      assert(u != v);
			int a = belong[MP(u, v)];
			int b = belong[MP(v, u)];
			//      assert(belong.count(MP(u, v)));
			//      assert(belong.count(MP(v, u)));
			//              assert(a != b || a == 0 || b == 0);
			//if (a == b && a != 0) while(1);
			int w = weight.count(MP(u,v)) ? weight[MP(u,v)] : 0;
			gragh[a].push_back(MP(b, w));
			//gragh[b].push_back(MP(a, w));
		}
	}
	printf("%d\n", dijkstra(s, t));

	return 0;
}

// hehe ~       

