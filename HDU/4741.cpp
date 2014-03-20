// File Ne: hdu4741.cpp
// Author: YgYue
// Creed Time: Thu Sep 19 13:49:36 2013
//heers 
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
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
struct Point {
    long double x, y, z;
    Point(){}
    Point(long double x, long double y, long double z) : x(x), y(y), z(z) {}
    Point operator - (const Point &b) {
        return Point(x - b.x, y - b.y, z - b.z);
    }
    Point operator + (const Point &b) {
        return Point(x + b.x, y + b.y, z + b.z);
    }
    Point operator * (const Point &b) {
        return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.z);
    }
    Point operator * (const long double &b) {
        return Point(x * b, y * b, z * b);
    }
    long double operator % (const Point &b) {
        return x * b.x + y * b.y + z * b.z;
    }
    long double len2() {
        return x * x + y * y + z * z;
    }
    long double len() {
        return sqrt(x * x + y * y + z * z);
    }
    void init() {
        double tx, ty, tz;
        scanf("%lf%lf%lf",&tx,&ty,&tz);
        x = tx; y = ty; z = tz;
    }
    void print(char c) {
        printf("%.6f %.6f %.6f%c",(double) x,(double) y,(double) z, c);
    }
};
Point getLL(Point p1, Point p2, Point q1, Point q2) {
    Point p = q1 - p1;
    Point u = p2 - p1;
    Point v = q2 - q1;
    long double d = u.len2() * v.len2() - (u % v) * (u % v);
    long double s = ((p % u) * v.len2() - (p % v) * (u % v)) / d;
    return p1 + u * s;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    while (cases--) {
        Point p1, p2, q1, q2;
        p1.init(); p2.init();
        q1.init(); q2.init();
        Point a = getLL(p1, p2, q1, q2);
        Point b = getLL(q1, q2, p1, p2);
        printf("%.6f\n", (double) (a - b).len());
        a.print(' ');
        b.print('\n');
    }
    
    return 0;
}

// hehe ~

