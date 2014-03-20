// File Name: hdu3692.cpp
// Author: YangYue
// Created Time: Tue Oct  1 18:38:23 2013
//headers 
#include <cstdio>
#include <cassert>
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

const int MaxN = 205;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int dcmp(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
    double x, y, z;
    Point(){}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point operator - (const Point &b) { return Point(x - b.x, y - b.y, z - b.z); }
    Point operator + (const Point &b) { return Point(x + b.x, y + b.y, z + b.z); }
    Point operator * (const Point &b) { return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }
    Point operator * (const double &b) { return Point(x * b, y * b, z * b); }
    double operator % (const Point &b) { return x * b.x + y * b.y + z * b.z; }
    double len() { return sqrt(x * x + y * y + z * z); }
    double len2() { return x * x + y * y + z * z; }
    void init() { scanf("%lf%lf%lf",&x,&y,&z); }
    Point change(int c) {
        if (c == 0) return Point(x, y, z);
        if (c == 1) return Point(z, y, x);
        return Point(x, z, y);
    }
} p[MaxN], source, ppoint;
struct Point2D {
    double x, y;
    Point2D(){}
    Point2D(double x, double y) : x(x), y(y) {}
    Point2D operator - (const Point2D &b) { return Point2D(x - b.x, y - b.y); }
    Point2D operator + (const Point2D &b) { return Point2D(x + b.x, y + b.y); }
    Point2D operator * (const double &b) { return Point2D(x * b, y * b); }
    double operator * (const Point2D &b) { return x * b.y - y * b.x; }
    double operator % (const Point2D &b) { return x * b.x + y * b.y; }
    double len() { return sqrt(x * x + y * y); }
    double len2() { return x * x + y * y; }
    void init() { scanf("%lf%lf",&x,&y); }
    bool operator < (const Point2D &b) const {
        if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
        return dcmp(y - b.y) < 0;
    }
} q[MaxN], Hull[MaxN];
int Graham(Point2D* P,Point2D* Hull,int n)
{
    sort(P,P+n);
    int HTop = 0;
    for(int i = 0;i < n;i++)
    {
        // delete collinear points
        while(HTop > 1 && dcmp((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) HTop--;
        Hull[HTop++] = P[i];
    }
    int LTop = HTop;
    for(int i = n-2;i >= 0;i--)
    {
        while(HTop > LTop && dcmp((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) >= 0) HTop--;
        if(i) Hull[HTop++] = P[i];
    }
    return HTop;
}

int main()
{
    //freopen("in","r",stdin);

    double a, b, c, d;
    int n;
    while (1) {
        scanf("%lf%lf%lf%lf", &a,&b,&c,&d);
        if (dcmp(a) == 0 && dcmp(b) == 0 && dcmp(c) == 0 && dcmp(d) == 0) break;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) p[i].init();
        source.init();

        int change = 0;
        if (dcmp(c) == 0) {
            if (dcmp(a)) {
                change = 1;
                swap(a, c);
            }
            else {
                change = 2;
                swap(b, c);
            }
        }
        source = source.change(change);
        for (int i = 1; i <= n; ++i) p[i] = p[i].change(change);
        Point fvect = Point(a, b, c);
        fvect = fvect * (1. / fvect.len());
        ppoint = Point(0, 0, d / c);
        if ((source - ppoint) % fvect > eps) fvect = fvect * - 1.;
        
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            Point v = p[i] - source;
            if (dcmp(v % fvect) <= 0) { ++cnt; continue; }
            v = v * (1. / v.len());
            double l = ((ppoint - source) % fvect) * (1. / (v % fvect));
            v = source + v * l;
        //    assert(dcmp(v.x * a + v.y * b + v.z * c - d) == 0);
            q[i - 1] = Point2D(v.x, v.y);
        }
        if (cnt == n) puts("0.00");
        else if (cnt > 0) puts("Infi");
        else {
            int m = Graham(q, Hull, n);
            double area = 0;
            Hull[m] = Hull[0];
            for (int i = 0; i < m; ++i) area += Hull[i] * Hull[i+1];
            area *= 0.5;
            //printf("%.2f\n", fvect % Point(0, 0, 1));
            printf("%.2f\n", fabs(area / (fvect % Point(0, 0, 1))));
        }
    }
    
    return 0;
}

// hehe ~


