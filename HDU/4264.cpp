// File Name: hdu4264.cpp
// Author: YangYue
// Created Time: Fri Aug 16 19:01:51 2013
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

const double pi = acos(-1.0);
const int MaxN = 2005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n, pr;
int dcmp(double x) {
    return x < -eps ? -1 : x > eps;
}
struct Point {
    double x, y;
    Point(){}
    Point(double x, double y)
        : x(x), y(y) {}
    Point operator * (const double &b) {
        return Point(x * b, y * b);
    }
    Point operator / (const double &b) {
        return Point (x / b, y / b);
    }
    Point operator + (const Point &b) {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) {
        return Point(x - b.x, y - b.y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    double ang() {
        return atan2(y, x);
    }
    void init() {
        scanf("%lf%lf", &x, &y);
    }
};
struct cir {
    Point o; double r;
    cir(){}
    cir(Point o, double r)
        : o(o), r(r) {}
    void init() {
        o.init(); scanf("%lf", &r);
    }
} p[1005], red;
double dist(Point a) {
    return a.len();
}
Point trans(Point p, double ang) {
    return Point(p.x * cos(ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));
}
void do_it(double ang, cir a, cir b, Point &aa, Point &bb) {
    Point vect = b.o - a.o;
    //solve A
    vect = vect / vect.len();
    vect = trans(vect, ang);
    aa = a.o + vect * a.r;

    vect = a.o - b.o;
    vect = vect / vect.len();
    vect = trans(vect, ang);
    bb = b.o + vect * b.r;
}
PDD calc(cir a, cir b) {
    double d = dist(a.o - b.o);
    double rs = a.r + b.r;
    double ang = acos(rs / d);
    Point aa, bb, vect;
    if (dcmp(d - rs) == 0) {
        Point o = (a.o + b.o) / 2.0;
        Point vect = (a.o - b.o);
        vect = Point(vect.y, -vect.x);
        vect = vect / vect.len();
        double len = sqrt(sqr(pr) - o.len() * o.len());
        vect = vect * len;
        double res1 = (vect + o).ang();
        double res2 = (vect * -1 + o).ang();
        return MP(res1, res2);
    }
    
    do_it(ang, a, b, aa, bb);
    double l = 1, r = 1e5;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2.;
        Point tmp = (aa - bb) * mid + bb;
        if (dcmp(tmp.len() - pr) > 0) r = mid; else l = mid;
    }
    double res1 = (bb + (aa - bb) * l).ang();

    do_it(-ang, a, b, aa, bb);
    l = 1, r = 1e5;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2.0;
        Point tmp = (aa - bb) * mid + bb;
        if (dcmp(tmp.len() - pr) > 0) r = mid; else l = mid;
    }
    double res2 = (bb + (aa - bb) * l).ang();
    return MP(res1, res2);
}
PDD b[MaxN];
int main()
{
    //freopen("in","r",stdin);

    while (1) {
        scanf("%d%d", &n, &pr);
        if (n == 0 && pr == 0) break;
        red.init();
        int m = 0;
        for (int i = 0; i < n; ++i) {
            p[i].init();
            PDD tmp = calc(p[i], red);
            tmp.fi += pi;
            tmp.se += pi;
            //if (tmp.fi > tmp.se) swap(tmp.fi, tmp.se);
            if (tmp.fi > tmp.se) {
                b[m++] = MP(0, tmp.se);
                b[m++] = MP(tmp.fi, pi * 2.);
            } else {
                b[m++] = tmp;
            }
        }
        sort(b, b + m);
        double ans = 0;
        double l = 0, r = 0;
        for (int i = 0; i < m; ++i) {
            if (dcmp(l - b[i].fi) <= 0 && dcmp(b[i].fi - r) <= 0) {
                r = max(r, b[i].se);
            } else {
                ans += r - l;
                l = b[i].fi;
                r = b[i].se;
            }
        }
        ans += r - l;
        printf("%.4f\n", (2 * pi - ans) / pi / 2);
    }
    
    return 0;
}

// hehe ~

