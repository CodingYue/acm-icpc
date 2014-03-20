// File Name: hdu3124.cpp
// Author: YangYue
// Created Time: Fri Oct  4 19:24:48 2013
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
        if (dcmp(y - b.y) != 0) return dcmp(y - b.y) < 0;
        return dcmp(x - b.x) < 0;
    }
} c[MaxN];
double r[MaxN];
struct node {
    int idx;
    node(){}
    node(int idx) : idx(idx) {}
    bool operator < (const node &b) const { return c[idx] < c[b.idx]; }
};
bool intersectCC(Point c1, double r1, Point c2, double r2) {
    return dcmp((c1 - c2).len() - (r1 + r2)) <= 0;
}
pair<double, int> keyinc[MaxN], keydec[MaxN];
set<node> SET;
void del(int idx) {
    SET.erase(node(idx));
}
bool insert(int idx) {
    set<node> :: iterator it, pre, succ;
    it = SET.insert(node(idx)).fi;
    pre = succ = it;
    if (it != SET.begin()) --pre;
    if (it != SET.end()) ++succ;
    if (it->idx != pre->idx && intersectCC(c[it->idx], r[it->idx], c[pre->idx], r[pre->idx])) return 1;
    if (it->idx != succ->idx && intersectCC(c[it->idx], r[it->idx], c[succ->idx], r[succ->idx])) return 1;
    return 0;
}
bool check(int n) {
    for (int i = 0; i < n; ++i) {
        keyinc[i] = make_pair(c[i].x - r[i], i);
        keydec[i] = make_pair(c[i].x + r[i], i);
    }
    sort(keyinc, keyinc + n);
    sort(keydec, keydec + n);
    SET.clear();
    for (int i = 0, j = 0; i < n || j < n; ) {
        if (i == n) del(keydec[j++].se);
        else if (j == n) {
            if (insert(keyinc[i++].se)) return 1;
        } else
        if (dcmp(keyinc[i].fi - keydec[j].fi) < 0) {
            if (insert(keyinc[i++].se)) return 1;
        } else del(keydec[j++].se);
    }
    return 0;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    while (cases--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            c[i].init(); scanf("%lf", r + i);
        }
        double l = 0, r = 2e5;
        while (l + 1e-8 < r) {
            double mid = (l + r) / 2;
            for (int i = 0; i < n; ++i) ::r[i] += mid / 2;
            if (check(n)) r = mid; else l = mid;
            for (int i = 0; i < n; ++i) ::r[i] -= mid / 2;
        }
        printf("%.6f\n", r);
    }
    
    return 0;
}

// hehe ~

