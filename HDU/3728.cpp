// File Name: hdu3728.cpp
// Author: YangYue
// Created Time: Thu Oct  3 18:32:23 2013
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

const int MaxN = 1005;
const double eps = 1e-8;
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
    Point rot90() { return Point(-y, x); }
    double operator * (const Point &b) { return x * b.y - y * b.x; }
    double operator % (const Point &b) { return x * b.x + y * b.y; }
    double len() { return sqrt(x * x + y * y); }
    double len2() { return x * x + y * y; }
    double ang() {
        double angle = atan2(y, x);
        if (angle < -eps) angle += 2 * pi;
        return angle;
    }
    void init() { scanf("%lf%lf", &x,&y); }
    bool operator == (const Point &b) {
        return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
    }
    bool operator < (const Point &b) const {
        if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
        return dcmp(y - b.y) < 0;
    }
} c[MaxN];
double r[MaxN];
int check(Point p, Point c, double r) {
    return dcmp((p - c).len2() - r * r) == 0;
}
int tot;
map<Point, int> MAP;
int insert(Point p) {
    if (!MAP.count(p)) MAP[p] = tot++;
    return MAP[p];
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
bool E[MaxN][MaxN];
int W[MaxN][MaxN];
int w[MaxN];
int dis[MaxN][MaxN];
bool inque[MaxN][MaxN];
int SPFA(int S, int T, int tot, int n) {
    for (int i = 0; i < tot; ++i)
        for (int j = 0; j <= n; ++j) dis[i][j] = INF;
    dis[S][w[S]] = w[S];
    memset(inque, 0, sizeof inque);
    inque[S][w[S]] = 1;
    queue<PII> que; que.push(MP(S, w[S]));
    while (!que.empty()) {
        int u = que.front().fi;
        int k = que.front().se;
        que.pop();
        for (int v = 0; v < tot; ++v) if (E[u][v]) {
            int j = min(w[v], k);
            j = min(j, W[u][v]);
            int tmp = max(dis[u][k], w[v]);
            tmp = max(tmp, W[u][v]);
            if (tmp < dis[v][j]) {
                dis[v][j] = tmp;
                if (!inque[v][j]) {
                    que.push(MP(v, j));
                    inque[v][j] = 1;
                }
            }
        }
        inque[u][k] = 0;
    }
    int res = INF;
    for (int i = 0; i <= n; ++i) if (dis[T][i] != INF) res = min(res, dis[T][i] - i);
    if (res == INF) return -1;
    return res;
}
void ins(int u, int v) {
    E[u][v] = E[v][u] = 1;
}
bool cover(Point p, Point c, double r) {
    return dcmp((p - c).len2() - r*r) <= 0;
}
struct Key {
    double first; int second;
    Key(){}
    Key(double first, int second) : first(first), second(second) {}
    bool operator < (const Key &b) const {
        if (dcmp(first - b.first) != 0) return dcmp(first - b.first) < 0;
        return second < b.second;
    }
    bool operator == (const Key &b) const {
        return dcmp(first - b.first) == 0 && second == b.second;
    }
} keys[MaxN];
int main()
{
    //freopen("in","r",stdin);

    int n;
    int Cas = 0;
    while (scanf("%d", &n), n) {
        Point st, ed; st.init(); ed.init();
        for (int i = 0; i < n; ++i) {
            c[i].init(); scanf("%lf", r + i);
        }
        tot = 0; MAP.clear();
        insert(st); insert(ed);
        memset(E, 0, sizeof E);

        for (int i = 0; i < n; ++i) {
            int m = 0;
            if (check(st, c[i], r[i])) keys[m++] = Key((st - c[i]).ang(), MAP[st]);
            if (check(ed, c[i], r[i])) keys[m++] = Key((ed - c[i]).ang(), MAP[ed]);
            for (int j = 0; j < n; ++j) if (i != j) {
                vector<Point> root = getCC(c[i], r[i], c[j], r[j]);
                if (root.size() == 0) continue;
                int u = insert(root[0]);
                int v = insert(root[1]);
                keys[m++] = Key((root[0] - c[i]).ang(), u);
                keys[m++] = Key((root[1] - c[i]).ang(), v);
            }
            sort(keys, keys + m); m = unique(keys, keys + m) - keys;
            keys[m] = keys[0];
            for (int j = 0; j < m; ++j) ins(keys[j].second, keys[j+1].second);
        }
        memset(w, 0, sizeof w);
        memset(W, 0, sizeof W);
        for (map<Point, int> :: iterator it = MAP.begin(); it != MAP.end(); ++it) {
            Point p = it->first;
            for (int i = 0; i < n; ++i) if (cover(p, c[i], r[i])) ++w[it->second];
        }
        map<Point, int> :: iterator x, y;
        for (x = MAP.begin(); x != MAP.end(); ++x)
        for (y = MAP.begin(); y != MAP.end(); ++y) if (x != y && E[x->se][y->se]) {
            for (int i = 0; i < n; ++i) if (cover(x->fi, c[i], r[i]) && cover(y->fi, c[i], r[i])) ++W[x->se][y->se];
        }
        printf("Case %d: ", ++Cas);
        printf("%d\n", SPFA(0, 1, tot, n));
    }

    return 0;
}

// hehe ~
