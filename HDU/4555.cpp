
// File Name: tmp.cpp
// Author: YangYue
// Created Time: Sun May 19 22:22:50 2013
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
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

struct Point3D {
    LL x, y, z;
    Point3D(){}
    Point3D(LL x, LL y, LL z)
        : x(x), y(y), z(z) {}
    Point3D operator * (const Point3D &b) {
        LL i = y * b.z - b.y * z;
        LL j = z * b.x - b.z * x;
        LL k = x * b.y - b.x * y;
        return Point3D(i, j, k);
    }
    Point3D operator - (const Point3D &b) {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    int init() {
        return scanf("%lld%lld%lld", &x, &y, &z);
    }
    bool operator == (const Point3D &b) {
        return x == b.x && y == b.y && z == b.y;
    }
};
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a % b);
}
LL x0, yy0;
void exgcd(long long a,long long b)
{
    if (b==0){x0=1;yy0=0;return;}
    exgcd(b,a%b);
    long long t=x0;x0=yy0;yy0=t-a/b*yy0;
    return;
}
LL calc(LL a, LL b, LL c, LL x1, LL x2, LL yy1, LL y2) {
    if (c<0) {a=-a;b=-b;c=-c;}
    if (a<0) {a=-a;long long t=x1;x1=-x2;x2=-t;}
    if (b<0) {b=-b;long long t=yy1;yy1=-y2;y2=-t;}
    if (a==0 && b==0)
    {
        if (c==0)
        {
            return (x2-x1+1)*(y2-yy1+1);
            return 0;
        }
        return 0;
    }
    else if (a==0)
    {
        if (c %b ==0)
            if (c/b<=y2 && c/b>=yy1) return x2-x1+1;
        return 0;
    }
    else if (b==0)
    {
        if (c%a==0)
            if (c/a<=x2 && c/a>=x1) return y2-yy1+1;
        return 0;
    }

    long long d=gcd(a,b);
    if (c%d!=0) return 0;

    a=a/d;b=b/d;c=c/d;
    exgcd(a,b);
    x0=x0*c;yy0=yy0*c;

    double tx2=x2,tx1=x1,tx0=x0,ta=a,tb=b,ty1=yy1,ty2=y2,ty0=yy0;
    long long down1=floor(((tx2-tx0)/tb)),down2=floor(((ty0-ty1)/ta));
    long long r=min(down1,down2);
    long long up1=ceil(((tx1-tx0)/tb)),up2=ceil(((ty0-ty2)/ta));
    long long l=max(up1,up2);
    if (r<l) return 0;
    else return r - l + 1;
}
int main()
{
    //freopen("tmp.in","r",stdin);

    Point3D A, B, C;

    while (A.init() != EOF) {
        B.init();
        C.init();
        LL lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        Point3D fvect = (C - A) * (B - A);
        if (fvect == Point3D(0, 0, 0)) {
            puts("-1");
            continue;
        }
        LL a = fvect.x, b = fvect.y, c = fvect.z;

        LL d = A.x * a + A.y * b + A.z * c;
        LL ans = 0;
        for (LL z = lz; z <= rz; ++z) {
            ans += calc(a, b, d - c * z, lx, rx, ly, ry);
        }
        cout << ans << endl;
    }
    return 0;
}

    // hehe ~

