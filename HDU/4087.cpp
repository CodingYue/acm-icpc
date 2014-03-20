// File Name: hdu4087.cpp
// Author: YangYue
// Created Time: Tue Oct  1 20:28:19 2013
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
const double pi = acos(- 1.0);

struct matrix {
    double mat[4][4];
};
matrix unit() {
    matrix res;
    memset(res.mat, 0, sizeof res.mat);
    for (int i = 0; i < 4; ++i) res.mat[i][i] = 1;
    return res;
}
matrix scale(double a, double b, double c) {
    matrix res = unit();
    res.mat[0][0] = a;
    res.mat[1][1] = b;
    res.mat[2][2] = c;
    return res;
}
matrix rotate(double x, double y, double z, double d) {
    d = pi * d / 180.;
    matrix res = unit();
    double cosd = cos(d);
    double sind = sin(d);
    res.mat[0][0] = cosd + sqr(x) * (1-cosd);
    res.mat[0][1] = x*y*(1-cosd)+z*sind;
    res.mat[0][2] = z*x*(1-cosd)-y*sind;
    res.mat[1][0] = x*y*(1-cosd)-z*sind;
    res.mat[1][1] = cosd+sqr(y)*(1-cosd);
    res.mat[1][2] = z*y*(1-cosd)+x*sind;
    res.mat[2][0] = x*z*(1-cosd)+y*sind;
    res.mat[2][1] = y*z*(1-cosd)-x*sind;
    res.mat[2][2] = cosd+sqr(z)*(1-cosd);
    return res;
}
matrix translate(double a, double b, double c) {
    matrix res = unit();
    res.mat[3][0] = a;
    res.mat[3][1] = b;
    res.mat[3][2] = c;
    return res;
}
matrix mul(matrix a, matrix b) {
    matrix res; memset(res.mat, 0, sizeof res.mat);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k) res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return res;
}
matrix fpow(matrix a, int t) {
    matrix res = unit();
    for (; t; t >>= 1, a = mul(a, a))
        if (t & 1) res = mul(res, a);
    return res;
}
matrix dfs(int times) {
    matrix res = unit();
    while (1) {
        char op[20];
        scanf("%s", op);
        if (op[0] == 'e') {
            break;
        }
        if (op[0] == 'r' && op[1] == 'e') {
            int t; scanf("%d", &t);
            res = mul(res, dfs(t));
        }
        if (op[0] == 'r' && op[1] == 'o') {
            double a, b, c, d; scanf("%lf%lf%lf%lf", &a,&b,&c,&d);
            double len = sqrt(a * a + b * b + c * c);
            a /= len;
            b /= len;
            c /= len;
            res = mul(res, rotate(a, b, c, d));
        }
        if (op[0] == 't') {
            double a, b, c; scanf("%lf%lf%lf", &a,&b,&c);
            res = mul(res, translate(a, b, c));
        }
        if (op[0] == 's') {
            double a, b, c; scanf("%lf%lf%lf", &a,&b,&c);
            res = mul(res, scale(a, b, c));
        }
    }
    return fpow(res, times);
}
double fuck(double x) {
    if (fabs(x) < 1e-6) return 1e-4;
    return x;
}
int main()
{
    //freopen("in","r",stdin);

    int n; 
    while (scanf("%d",&n), n) {
        matrix T = dfs(1);
        for (int i = 0; i < n; ++i) {
            double a, b, c; scanf("%lf%lf%lf", &a, &b, &c);
            matrix p; memset(p.mat, 0, sizeof p.mat);
            p.mat[0][0] = a;
            p.mat[0][1] = b;
            p.mat[0][2] = c;
            p.mat[0][3] = 1;
            p = mul(p, T);
            printf("%.2f %.2f %.2f\n", fuck(p.mat[0][0]), fuck(p.mat[0][1]), fuck(p.mat[0][2]));
        }
        printf("\n");
    }

    return 0;
}

// hehe ~

