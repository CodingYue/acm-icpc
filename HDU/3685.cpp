// File Name: hdu3685.cpp
// Author: YangYue
// Created Time: Thu Oct  3 16:06:57 2013
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

const int MaxN = 200005;
const double eps = 1e-8;
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
    double operator * (const Point &b) { return x * b.y - y * b.x; }
    double operator % (const Point &b) { return x * b.x + y * b.y; }
    double len() { return sqrt(x * x + y * y); }
    double len2() { return x * x + y * y; }
    void init() { scanf("%lf%lf", &x, &y); }
    bool operator < (const Point &b) const {
        if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
        return dcmp(y - b.y) < 0;
    }
} p[MaxN], hull[MaxN];
Point getCenter(Point *p, int n) {
    p[n] = p[0];
    Point res = Point(0,0);
    double area = 0;
    for (int i = 0; i < n; ++i) {
        area += p[i] * p[i+1] * 0.5;
        res = res + (p[i] + p[i+1]) * (p[i] * p[i+1] / 6.0);
    }
    return res / area;
}
int Graham(Point* P,Point* Hull,int n)
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
bool check(Point p, Point p1, Point p2) {
    if (dcmp((p - p1) % (p2 - p1)) <= 0) return 0;
    if (dcmp((p - p2) % (p1 - p2)) <= 0) return 0;
    return 1;
}
int count(Point center, Point *p, int n) {
    int res = 0;
    p[n] = p[0];
    for (int i = 0; i < n; ++i) res += check(center, p[i], p[i+1]);
    return res;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    while (cases--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) p[i].init();
        Point center = getCenter(p, n);
        int m = Graham(p, hull, n);
        printf("%d\n", count(center, hull, m));
    }
    
    return 0;
}

// hehe ~

