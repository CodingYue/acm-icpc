// File Name: hdu3239.cpp
// Author: YangYue
// Created Time: Sat Oct  5 16:59:10 2013
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

double pi = acos(- 1.0);
const int MaxN = 205;
const double eps = 1e-6;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int dcmp(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
    double x, y;
    Point(){}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
    Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
    Point operator * (const double &b) { return Point(x * b, y * b); }
    Point operator / (const double &b) { return Point(x / b, y / b); }
    Point rot90() { return Point(-y, x); }
    Point rot(double ang) { return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); }
    double ang() { double tmp = atan2(y, x); if (tmp < -eps) tmp += 2 * pi; return tmp; }
    double operator * (const Point &b) { return x * b.y - y * b.x; }
    double operator % (const Point &b) { return x * b.x + y * b.y; }
    double len2() { return x * x + y * y; }
    double len() { return sqrt(x * x + y * y); }
    void init() { scanf("%lf%lf", &x,&y); }
    bool operator == (const Point &b) const {
        return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
    }
    bool operator < (const Point &b) const {
        if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
        return dcmp(y - b.y) < 0;
    }
} c[MaxN];
struct circle {
    Point c; double r;
    circle(){}
    circle(Point c, double r) : c(c), r(r) {}
    bool operator == (const circle &b) const {
        return c == b.c && dcmp(r - b.r) == 0;
    }
    bool operator < (const circle &b) const {
        if (dcmp(r - b.r) != 0) return dcmp(r - b.r) < 0;
        return c < b.c;
    }
} cir[MaxN];
double cal(Point c, double r, double ang1, double ang2) {
    double ang = ang2 - ang1;
    if (dcmp(ang) == 0) return 0;
    Point p1 = c + Point(r, 0).rot(ang1);
    Point p2 = c + Point(r, 0).rot(ang2);
    return r * r * (ang - sin(ang)) + p1 * p2;
}
double area[MaxN];
int cover[MaxN];
pair<double, int> keys[MaxN * 10];
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
bool cmp(const pair<double,int> &a, const pair<double,int> &b) {
    if (dcmp(a.fi - b.fi) != 0) return dcmp(a.fi - b.fi) < 0;
    return a.se > b.se;
}
bool check(Point c1, double r1, Point c2, double r2) {
    return dcmp((c1 - c2).len() - (r2 - r1)) <= 0;
}
double solve(int cur, int n) {
    int m = 0;
    for (int i = 0; i < n; ++i) if (i != cur) {
        if (check(cir[cur].c, cir[cur].r, cir[i].c, cir[i].r)) { ++cover[cur]; continue; }
        vector<Point> root = getCC(cir[cur].c, cir[cur].r, cir[i].c, cir[i].r);
        if (root.size() == 0) continue;
        double ang1 = (root[0] - cir[cur].c).ang();
        double ang2 = (root[1] - cir[cur].c).ang();
        if (dcmp(ang1 - ang2) == 0) continue;
        if (dcmp(ang1 - ang2) >= 0) {
            keys[m++] = make_pair(0, 1);
            keys[m++] = make_pair(ang2, -1);
            keys[m++] = make_pair(ang1, 1);
            keys[m++] = make_pair(2*pi, -1);
        } else {
            keys[m++] = make_pair(ang1, 1);
            keys[m++] = make_pair(ang2, -1);
        }
    }
    keys[m++] = make_pair(0, 0);
    keys[m++] = make_pair(2 * pi, - 100000);
    sort(keys, keys + m, cmp);
    double res = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        cnt += keys[i].second;
        double tarea = cal(cir[cur].c, cir[cur].r, keys[i].first, keys[i+1].first);
        if (cnt + cover[cur] == 0) res += tarea;
        if (cnt < -10) continue;
        area[cover[cur] + cnt] -= tarea;
        area[cover[cur] + cnt + 1] += tarea;
    }
    return res;
}
int main()
{
    //freopen("in","r",stdin);

    int cas = 0;
    while (1) {
        Point p[4];
        for (int i = 0; i < 4; ++i) p[i].init();
        if (dcmp(p[0].x) == 0) break;
        printf("Case %d: ", ++cas);
        memset(cover, 0, sizeof cover);
        memset(area, 0, sizeof area);
        int n = 0;
        for (int i = 0; i < 2; ++i)
        for (int j = 2; j < 4; ++j) if ((p[i]-p[j]).len2() > eps) 
            cir[n++] = circle((p[i] + p[j]) / 2, (p[i] - p[j]).len() / 2);
        sort(cir, cir + n); n = unique(cir, cir + n) - cir;
        double res = 0;
        for (int i = 0; i < n; ++i) res += solve(i, n);
        printf("%.3f\n\n", (res - area[n]) * 0.5);
    }
    
    return 0;
}

// hehe ~


