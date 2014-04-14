// File Name: 1C.cpp
// Author: YangYue
// Created Time: Thu Apr 10 18:53:56 2014
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

const int MaxN = 10005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = 3.14159265358979323846;
struct Point {
	double x, y, z;
	Point(){}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator + (const Point &b) { return Point(x + b.x, y + b.y, z + b.z); }
	Point operator - (const Point &b) { return Point(x - b.x, y - b.y, z - b.z); }
	Point operator * (const Point &b) { return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }
	Point operator * (const double &b) { return Point(x * b, y * b, z * b); }
	double operator % (const Point &b) { return x * b.x + y * b.y + z * b.z; }
	double len2() { return x * x + y * y + z * z; }
	double len() { return sqrt(x * x + y * y + z * z); }
} p[MaxN];
struct EDGE {
	int u, v;
	double w;
	EDGE(){}
	EDGE(int u, int v, double w) :
		u(u), v(v), w(w) {}
	bool operator < (const EDGE &b) const {
		return w < b.w;
	}
} edge[MaxN];
int fa[MaxN];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	while (cases--) {
		double D, L;
		int C;
		scanf("%lf %lf %d", &D, &L, &C);
		double r = D / 2;
		for (int i = 0; i < C; ++i) {
			double theta1, theta2;
			scanf("%lf %lf", &theta1, &theta2);
			theta1 += 90;
			theta2 += 180;
			theta1 = theta1 / 180 * pi;
			theta2 = theta2 / 180 * pi;
			double x = r * cos(theta1);
			double y = r * sin(theta1) * cos(theta2);
			double z = r * sin(theta1) * sin(theta2);
			p[i] = Point(x, y, z);
		}
		int m = 0;
		for (int i = 0; i < C; ++i)
			for (int j = i + 1; j < C; ++j) {
				double theta = acos(p[i] % p[j] / (p[i].len() * p[j].len()));
				edge[m++] = EDGE(i, j, r * theta);
			}
		sort(edge, edge + m);
		double sum = 0;
		for (int i = 0; i < C; ++i) fa[i] = i;
		for (int i = 0; i < m; ++i) {
			int u = edge[i].u, v = edge[i].v;
			double w = edge[i].w;
			if (get(u) != get(v)) {
				fa[get(u)] = get(v);
				sum += w;
			}
		}
		if (sum > L + eps) puts("N"); else puts("Y");
	}
	
	return 0;
}

// hehe ~


