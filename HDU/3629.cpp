// File Name: hdu3629.cpp
// Author: YangYue
// Created Time: Sat Oct  5 18:26:26 2013
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
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = acos(- 1.0);

struct Point {
    double x, y;
    Point(){}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
    Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
    Point operator * (const double &b) { return Point(x * b, y * b); }
    Point operator / (const double &b) { return Point(x / b, y / b); }
    double ang() { double tmp = atan2(y, x); if (tmp < -eps) tmp += 2 * pi; return tmp; }
    void init() { scanf("%lf%lf", &x,&y); }
} p[MaxN];
double ang[MaxN];
LL solve(int cur, int n) {
    LL res = (LL) (n - 1) * (n - 2) * (n - 3) / 6;
    int m = 0;
    for (int i = 0; i < n; ++i) if (i != cur) {
        ang[m++] = (p[i]-p[cur]).ang();
    }
    sort(ang, ang + m);
    for (int i = 0; i < m; ++i) ang[i+m] = ang[i] + 2 * pi;
    int k = 1;
    for (int i = 0; i < m; ++i) {
        while (fabs(ang[k] - ang[i]) - pi < 0) ++k;
        res -= (LL) (k - i - 1) * (k - i - 2) / 2;
    }
    return res;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    while (cases--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) p[i].init();
        LL res = (LL) n * (n - 1) * (n - 2) * (n - 3) / 24;
        for (int i = 0; i < n; ++i) res -= solve(i, n);
        cout << res << endl;
    }
    
    return 0;
}

// hehe ~

