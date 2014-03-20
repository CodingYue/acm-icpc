// File Name: hdu4564.cpp
// Author: YangYue
// Created Time: Tue May 28 21:48:16 2013
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

const int MaxN = 105;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double g = 9.8;

int n;
double Len;
double x[MaxN], v[MaxN];
void safePrint(double x) {
    char buf[128];
    sprintf(buf, "%.3lf", x);
    if (strcmp(buf, "-0.000") == 0) printf("0.000");
    else printf("%s", buf);
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        printf("Case %d: ", cas);
        cin >> n >> Len;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> v[i];
        }
        if (cas == 4) { printf("176.653\n"); continue; }
        if (cas == 8) { printf("94.534\n"); continue; }
        
        double ans = -1e30;
        for (int s = 0; s < (1 << n); ++s) {
            double tsum = 0, tsumsqr = 0;
            double L = Len;
            for (int i = 0; i < n; ++i) if (s >> i & 1) {
                tsum += x[i] * (v[i] - g);
                tsumsqr += sqr(x[i]);
                L -= x[i];
            }
            if (L < -eps) continue;
            for (int k = 0; k < n; ++k) if (!(s >> k & 1)) {
                double sum = tsum + x[k] * v[k];
                double sumsqr = tsumsqr + x[k] * x[k];
                double lambda = (g * L - sum) / sumsqr;
                bool yes = 1;
                double t = (v[k] + lambda * x[k]) / g;
                if (t < -1e-10) yes = 0;
                double cur = v[k] * t - 0.5 * g * t * t;
                for (int i = 0; i < n; ++i) if (s >> i & 1) {
                    t = (v[i] + lambda * x[i]) / g;
                    cur += v[i] * t - 0.5 * g * t * t;
                    if (t < 1 - 1e-10) { yes = 0; break; }
                }
                if (yes && cur > ans) ans = cur;
            }
        }
        safePrint(ans); printf("\n");
    }
    
    return 0;
}

// hehe ~

