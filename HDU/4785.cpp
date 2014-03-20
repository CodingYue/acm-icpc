// File Name: hdu4785.cpp
// Author: YangYue
// Created Time: Tue Nov 26 12:52:28 2013
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

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int dcmp(double x) {
    return x < -eps ? -1 : x > eps;
}
struct Point {
    double x, y;
    Point (){}
    Point(double x, double y) : x(x), y(y) {}
    Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
    Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
    Point operator * (const double &b) { return Point(x * b, y * b); }
    Point operator / (const double &b) { return Point(x / b, y / b); }
    double operator * (const Point &b) { return x * b.y - y * b.x; }
    double operator % (const Point &b) { return x * b.x + y * b.y; }
    double len2() { return x * x + y * y; }
    double len() { return sqrt(x * x + y * y); }
    bool operator < (const Point &b) const {
        if (dcmp(y - b.y) != 0) return dcmp(y - b.y) < 0;
        return dcmp(x - b.x) < 0;
    }
    void init() {
        scanf("%lf%lf", &x, &y);
    }
} point[105][105], robot[105];
struct Segment {
    Point s, e;
    double angle;
    Segment(){}
    Segment(Point s, Point e)
        : s(s), e(e) {
            angle = atan2(e.y - s.y, e.x - s.x);
        }
} ;
double xmul(Point a, Point b, Point c) {
    return (b-a) * (c-a);
}
Point get_intersect(Segment s1, Segment s2) {
    double u = xmul(s1.s, s1.e, s2.s);
    double v = xmul(s1.e, s1.s, s2.e);
    Point t;
    t.x = (s2.s.x * v + s2.e.x * u) / (u + v);
    t.y = (s2.s.y * v + s2.e.y * u) / (u + v);
    return t;
}
bool cmp(Segment a, Segment b) {
    if (dcmp(a.angle - b.angle) == 0) return dcmp(xmul(a.s, a.e, b.s)) < 0;
    return dcmp(a.angle - b.angle) < 0;
    return 0;
}
bool IsParallel(Segment P, Segment Q) {
    return dcmp((P.e - P.s) * (Q.e - Q.s)) == 0;
}
Segment deq[205];
int HalfPlaneIntersect(Segment seg[], int n, Point hull[]) {
    cmp(seg[0], seg[7]);
    sort(seg, seg + n, cmp);
    int tmp = 1;
    for (int i = 1; i < n; ++i) {
        if (dcmp(seg[i].angle - seg[tmp - 1].angle) != 0) {
            seg[tmp++] = seg[i];
        }
    }
    n = tmp;
    deq[0] = seg[0]; deq[1] = seg[1];
    int front = 0, tail = 1;
    for (int i = 2; i < n; ++i) {
        if(IsParallel(deq[tail], deq[tail-1]) || IsParallel(deq[front], deq[front+1])) return 0;
        while (front < tail && dcmp(xmul(seg[i].s, seg[i].e, get_intersect(deq[tail], deq[tail - 1]))) < 0) --tail;
        while (front < tail && dcmp(xmul(seg[i].s, seg[i].e, get_intersect(deq[front], deq[front+1]))) < 0) ++front;
        deq[++tail] = seg[i];
    }
    while(front < tail && xmul(deq[front].s, deq[front].e, get_intersect(deq[tail], deq[tail-1])) < -eps) tail--;
    while(front < tail && xmul(deq[tail].s, deq[tail].e, get_intersect(deq[front], deq[front+1])) < -eps) front++;
    int cnt = 0;
    deq[++tail] = deq[front];
    for (int i = front; i < tail; ++i) hull[cnt++] = get_intersect(deq[i], deq[i+1]);
    return cnt;
}
int mincowski(int n, int m, Point *p1, Point *p2, Point *p) {
    int size = 0;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) if (p1[i] < p1[s1]) s1 = i;
    for (int i = 0; i < m; ++i) if (p2[i] < p2[s2]) s2 = i;
    p1[n] = p1[0];
    p2[m] = p2[0];

    int i = s1, j = s2;
    do {
        p[size++] = p1[i] + p2[j];
        int cmp = dcmp((p1[i+1] - p1[i]) * (p2[j+1] - p2[j]));
        if (cmp > 0) {
            ++i;
        } else if (cmp < 0) ++j;
        else {
            ++i;
            ++j;
        }
        i %= n;
        j %= m;
    } while(i != s1 || j != s2);
    return size;
}
struct Polygon {
    int M;
    vector<Point> p;
    void init(int _M, Point *_p) {
        M = _M;
        p.resize(M);
        for (int i = 0; i < M; ++i) p[i] = _p[i];
        if (dcmp((p[1]-p[0]) * (p[2]-p[1])) < 0) reverse(p.begin(), p.end());
        p.push_back(p[0]);
    }
    Point& operator [](const int &i) { return p[i]; }
} poly[MaxN];
pair<double, int> keys[MaxN];
double get(Point a, Point b, Point c) {
    double t;
    if (fabs(a.x-b.x) > eps) t = (c.x-a.x)/(b.x-a.x);
    else t = (c.y-a.y)/(b.y-a.y);
    t = max(min(t,1.0),0.0);
    return t;
}
double solve(int n) {
    double res = 0;
    for (int i = 0; i < n; ++i)
    for (int x = 0; x < poly[i].M; ++x) {
        int keysize = 0;
        for (int k = 0; k < n; ++k) if (k != i)
            for (int y = 0; y < poly[k].M; ++y) {
                int t1 = dcmp(xmul(poly[i][x], poly[i][x+1], poly[k][y]));
                int t2 = dcmp(xmul(poly[i][x], poly[i][x+1], poly[k][y+1]));
                if (!t1 && !t2) {
                    if (k < i && dcmp((poly[k][y+1]-poly[k][y])%(poly[i][x+1]-poly[i][x])) >= 0) {
                        double d1 = get(poly[i][x], poly[i][x+1], poly[k][y]);
                        double d2 = get(poly[i][x], poly[i][x+1], poly[k][y+1]);
                        keys[keysize++] = make_pair(d1, 1);
                        keys[keysize++] = make_pair(d2, -1);
                    }
                } else if ((t1 >= 0 && t2 < 0) || (t1 < 0 && t2 >= 0)) {
                    double d1 = xmul(poly[k][y], poly[k][y+1], poly[i][x]);
                    double d2 = xmul(poly[k][y], poly[k][y+1], poly[i][x+1]);
                    int t = 1; if (t2 >= 0) t = -1;
                    keys[keysize++] = make_pair(max(min(d1/(d1-d2),1.),0.), t);
                }
            }
        sort(keys, keys + keysize);
        int cnt = 0;
        double s = 0, tmp = 0;
        bool f = 1;
        for (int j = 0; j < keysize; ++j) {
            cnt += keys[j].second;
            if (!cnt && !f) tmp = keys[j].first, f = 1;
            if (cnt && f) s += keys[j].first - tmp, f = 0;
        }
        s += 1. - tmp;
        res += (poly[i][x] * poly[i][x+1]) * s;
    }
    return res * 0.5;
}
int size[105];
Point Convex[105];
Segment segment[105];
int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    int cas = 0;
    while (cases--) {
        printf("Case #%d: ", ++cas);
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &size[i]);
            for (int j = 0; j < size[i]; ++j) point[i][j].init();
        }
        int m; scanf("%d", &m);
        for (int i = 0; i < m; ++i) robot[i].init();
        Point source = robot[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size[i]; ++j) point[i][j] = point[i][j] - source;
        }
        for (int i = 0; i < m; ++i) robot[i] = robot[i] - source;

        Point BL, TR; BL.init(); TR.init();
        BL = BL - source;
        TR = TR - source;

        double Xmin = 1e30, Xmax = -1e30, Ymin = 1e30, Ymax = -1e30;
        for (int i = 0; i < m; ++i) {
            Xmin = min(Xmin, robot[i].x);
            Xmax = max(Xmax, robot[i].x);
            Ymin = min(Ymin, robot[i].y);
            Ymax = max(Ymax, robot[i].y);
        }
        Segment limit[4];
        Xmax = TR.x - Xmax;
        Xmin = BL.x - Xmin;
        Ymax = TR.y - Ymax;
        Ymin = BL.y - Ymin; 
        limit[0] = Segment(Point(Xmax, Ymin), Point(Xmax, Ymax));
        limit[1] = Segment(Point(Xmax, Ymax), Point(Xmin, Ymax));
        limit[2] = Segment(Point(Xmin, Ymax), Point(Xmin, Ymin));
        limit[3] = Segment(Point(Xmin, Ymin), Point(Xmax, Ymin));
        for (int i = 0; i < m; ++i) robot[i].x *= -1, robot[i].y *= -1;
        for (int i = 0; i < n; ++i) {
            int nowsize = mincowski(size[i], m, point[i], robot, Convex);    
            Convex[nowsize] = Convex[0];
            for (int j = 0; j < nowsize; ++j) segment[j] = Segment(Convex[j], Convex[j+1]);
            for (int j = 0; j < 4; ++j)
                segment[nowsize++] = limit[j];
            nowsize = HalfPlaneIntersect(segment, nowsize, Convex);
            poly[i].init(nowsize, Convex);
        }
        double res = (Ymax - Ymin) * (Xmax - Xmin);
        res -= solve(n);
        printf("%.3f\n", res);
    }

    return 0;
}

// hehe ~

