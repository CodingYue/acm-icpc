// File Name: hdu4195.cpp
// Author: YangYue
// Created Time: Sat Oct  5 11:02:50 2013
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
#include <cassert>

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

const int MaxN = 200005;
const double eps = 1e-6;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = acos(- 1.0);

int dcmp(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
    double x, y;
    Point(){}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
    Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
    Point operator * (const double &b) { return Point(x * b, y * b); }
    Point operator / (const double &b) { return Point(x / b, y / b); }
    Point rot90(int t) { return Point(-y, x) * t; }
    double operator * (const Point &b) { return x * b.y - y * b.x; }
    double operator % (const Point &b) { return x * b.x + y * b.y; }
    double ang() { double tmp = atan2(y, x); if (tmp < -eps) tmp += 2 * pi; return tmp; }
    double len2() { return x * x + y * y; }
    void init() { scanf("%lf%lf", &x,&y); }
};
Point getCenter(Point A, Point B, Point C) {
    Point res = A + B;
    double tmp = ((C - B) % (A - C)) / ((B - A) * (C - B)); 
    res = res - (B - A).rot90(1) * tmp;
    res = res / 2;
    return res;
}
int main()
{
    //freopen("in","r",stdin);

    while (1) {
        char buf[20]; scanf("%s", buf);
        if (buf[0] == 'E') break;
        Point p[4];
        sscanf(buf, "%lf", &p[0].x);
        scanf("%lf", &p[0].y);
        p[1].init(); p[2].init();

        Point center = getCenter(p[0], p[1], p[2]);
        double len2 = (p[0] - center).len2();
        for (int i = 0; i < 3; ++i) assert(dcmp((p[i] - center).len2() - len2) == 0);
        for (int i = 0; i < 3; ++i) p[i] = p[i] - center; p[3] = p[0];
        double ang[3];
        for (int i = 0; i < 3; ++i) ang[i] = fabs(p[i+1].ang() - p[i].ang()) / (2 * pi);
        for (int n = 3; n <= 1000; ++n) {
            bool yes = 1;
            for (int i = 0; i < 3; ++i) {
                double t = ang[i] * n;
                int k = ang[i] * n + 0.5;
                if (fabs(t - k) > eps) yes = 0;
            }
            if (yes) {
                printf("%d\n", n);
                break;
            }
        }
    }
    
    return 0;
}

// hehe ~

