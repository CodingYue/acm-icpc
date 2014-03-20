// File Name: H.cpp
// Author: YangYue
// Created Time: Sat Sep 28 20:17:50 2013
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

const int MaxN = 2005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
int dcmp(double x) {
    return x < -eps ? -1 : x > eps;
}
struct Point {
    double x, y;
    Point(){}
    Point(double x, double y) :
        x(x), y(y) {}
    Point operator - (const Point &b) {
        return Point(x - b.x, y - b.y);
    }
    Point operator + (const Point &b) {
        return Point(x + b.x, y + b.y);
    }
    double operator * (const Point &b) {
        return x * b.y - y * b.x;
    }
    Point operator * (const double &b) {
        return Point(x * b, y * b);
    }
    double operator % (const Point &b) {
        return x * b.x + y * b.y;
    }
    Point rot90() {
        return Point(-y, x);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    double len2() {
        return x * x + y * y;
    }
    bool init() {
        return scanf("%lf%lf", &x,&y) != EOF;
    }
    bool operator < (const Point &b) const {
        if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
        return dcmp(y - b.y) < 0;
    }
    bool operator == (const Point &b) const {
        return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
    }
} c[MaxN], cc;
vector<Point> getCL(Point c, double r, Point p1, Point p2) {
    vector<Point> res;
    double x = (p1 - c) % (p2 - p1);
    double y = (p2 - p1).len2();
    double d = x * x - y * ((p1 - c).len2() - r * r);
    if (d < -eps) return res;
    if (d < 0) d = 0;
    Point q1 = p1 - ((p2 - p1) * (x / y));
    Point q2 = (p2 - p1) * (sqrt(d) / y);
    res.push_back(q1 - q2);
    res.push_back(q1 + q2);
    return res;
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
int n;
double r[MaxN];
bool check(double t) {
    r[0] = t;
    double L = - 1e6, R = 1e6;
    while (L + 1e-6 < R) {
        double x = (L + R) * 0.5;
        bool fl = 0, fr = 0;
        double up = 1e7, down = - 1e7;
        int a, b;
        for (int i = 0; i < n; ++i) {
            double dis = fabs(x - c[i].x);
            if (dis > r[i]) {
                if (c[i].x < x) fl = 1;
                else fr = 1;
                if (fl && fr) return 0;
            } else {
                vector<Point> root = getCL(c[i], r[i], Point(x, 0), Point(x, 1));
                sort(root.begin(), root.end());
                if (!i || dcmp(down - root[0].y) < 0) a = i, down = root[0].y;
                if (!i || dcmp(up - root[1].y) > 0) b = i, up = root[1].y;
                up = min(up, root[1].y);
                down = max(down, root[0].y);
            }
        }
        if (!fl && !fr && dcmp(up - down) >= 0) return 1;
        if (fl || fr) {
            if (fl) R = x; else L = x;
        } else {
            vector<Point> root = getCC(c[a], r[a], c[b], r[b]);
            if (root.size() == 0) return 0;
            double x0 = (root[0].x + root[1].x) * 0.5;
            if (x0 < x) R = x;
            else L = x;
        }
    }
    return 0;
}
int main()
{
    //freopen("in","r",stdin);

    while (c[0].init()) {
        double d; scanf("%lf", &d);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            c[i].init(); r[i] = d;
        }
        ++n;

    //    printf("%d\n", check(0.94));
        double l = 0, r = 1e6;
        if (!check(r)) printf("X\n");
        else {
            while (l + 1e-4 < r) {
                double mid = (l + r) * 0.5;
                if (check(mid)) r = mid; else l = mid;
            }
            printf("%.2f\n", l);
        }
    }

    return 0;
}

// hehe ~

