// File Name: 3DHull.cpp
// Author: YangYue
// Created Time: Fri May 17 10:00:59 2013
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
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
struct Point3D {
    double x, y, z;
    Point3D(){}
    Point3D(double x, double y, double z)
        : x(x), y(y), z(z) {}
    Point3D operator -(const Point3D &b) {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    Point3D operator /(const double &t) {
        return Point3D(x / t, y / t, z / t);
    }
    Point3D operator +(const double &t) {
        return Point3D(x + t, y + t, z + t);
    }
    Point3D operator +(const Point3D &b) {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }
    Point3D operator *(const double &t) {
        return Point3D(x * t, y * t, z * t);
    }
    double operator %(const Point3D &b) {
        return x * b.x + y * b.y + z * b.z;
    }
    Point3D operator *(const Point3D &b) {
        double i = y * b.z - b.y * z;
        double j = z * b.x - x * b.z;
        double k = x * b.y - b.x * y;
        return Point3D(i, j, k);
    }
    double len() {
        return sqrt( sqr(x) + sqr(y) + sqr(z) );
    }
    void init() {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
};
struct Plane {
    int a, b, c;
    bool ok;
};
Point3D xcross(Point3D a, Point3D b, Point3D c) {
    return (b - a) * (c - a);
}
struct Hull3D {
    int n, tricnt;
    int vis[MaxN][MaxN];
    Plane tri[MaxN];
    Point3D Ply[MaxN];
    
    void rebuild(int n_) {
        n = n_;
        tricnt = 0;
        memset(vis, 0, sizeof vis);
    }
    double area(Point3D a, Point3D b, Point3D c) {
        return ((b - a) * (c - a)).len();
    }
    double volume(Point3D a, Point3D b, Point3D c, Point3D d) {
        return (b - a) * (c - a) % (d - a);
    }
    double PtoPlane(Point3D &P, Plane f) {
        Point3D m = Ply[f.b] - Ply[f.a];
        Point3D n = Ply[f.c] - Ply[f.a];
        Point3D t = P - Ply[f.a];
        return m * n % t;
    }
    void deal(int p, int a, int b) {
        int f = vis[a][b];
        Plane add;
        if (tri[f].ok) {
            if ((PtoPlane(Ply[p], tri[f])) > eps) dfs(p, f);
            else {
                add.a = b;
                add.b = a;
                add.c = p;
                add.ok = 1;
                vis[p][b] = vis[a][p] = vis[b][a] = tricnt;
                tri[tricnt++] = add;
            }
        }
    }
    void dfs(int p, int cnt) {
        tri[cnt].ok = 0;
        deal(p, tri[cnt].b, tri[cnt].a);
        deal(p, tri[cnt].c, tri[cnt].b);
        deal(p, tri[cnt].a, tri[cnt].c);
    }
    bool same(int s, int e) {
        Point3D a = Ply[tri[s].a];
        Point3D b = Ply[tri[s].b];
        Point3D c = Ply[tri[s].c];
        return fabs(volume(a, b, c, Ply[tri[e].a])) < eps
            && fabs(volume(a, b, c, Ply[tri[e].b])) < eps
            && fabs(volume(a, b, c, Ply[tri[e].c])) < eps;
    }
    void construct() {
        tricnt = 0;
        if (n < 4) return;
        bool tmp = 1;
        for (int i = 1; i < n; ++i) {
            if ((Ply[0] - Ply[i]).len() > eps) {
                swap(Ply[1], Ply[i]);
                tmp = 0;
                break;
            }
        }
        if (tmp) return;
        tmp = 1;
        for (int i = 2; i < n; ++i) {
            if (((Ply[0] - Ply[1]) * (Ply[1] - Ply[i])).len() > eps) {
                swap(Ply[2], Ply[i]);
                tmp = 0;
                break;
            }
        }
        if (tmp) return;
        tmp = 1;
        for (int i = 3; i < n; ++i) {
            if (fabs((Ply[0] - Ply[1]) * (Ply[1] - Ply[2]) % (Ply[0] - Ply[i])) > eps) {
                swap(Ply[3], Ply[i]);
                tmp = 0;
                break;
            }
        }
        if (tmp) return;
        Plane add;
        for (int i = 0; i < 4; ++i) {
            add.a = (i + 1) % 4;
            add.b = (i + 2) % 4;
            add.c = (i + 3) % 4;
            add.ok = 1;
            if (PtoPlane(Ply[i], add) > 0) swap(add.b, add.c);
            vis[add.a][add.b] = vis[add.b][add.c] = vis[add.c][add.a] = tricnt;
            tri[tricnt++] = add;
        }
        for (int i = 4; i < n; ++i) {
            for (int j = 0; j < tricnt; ++j) {
                if (tri[j].ok && (PtoPlane(Ply[i], tri[j])) > eps) {
                    dfs(i, j);
                    break;
                }
            }
        }
        int cnt = tricnt; tricnt = 0;
        for (int i = 0; i < cnt; ++i) {
            if (tri[i].ok) {
                tri[tricnt++] = tri[i];
            }
        }
    }
    double Mindis(Point3D ask) {
        double res = 1e100;
        for (int i = 0; i < tricnt; ++i) {
            Point3D fvect = xcross(Ply[tri[i].a], Ply[tri[i].b], Ply[tri[i].c]);
            fvect = fvect / fvect.len();
            double cur = fvect % (ask - Ply[tri[i].a]);
            res = min(res, fabs(cur));
        }
        return res;
    }
} Hull;
int main()
{
    //freopen("3DHull.in","r",stdin);

    while (1) {
        cin >> n; if (n == 0) break;
        Hull.rebuild(n);
        for (int i = 0; i < n; ++i) {
            Hull.Ply[i].init();
        }
        Hull.construct();
        int Q; cin >> Q;
        while (Q--) {
            Point3D ask;
            ask.init();
            printf("%.4lf\n", Hull.Mindis(ask));
        }
    }
    return 0;
}

// hehe ~

