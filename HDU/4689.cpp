// File Name: hdu4689.cpp
// Author: YangYue
// Created Time: Wed Aug 21 12:50:56 2013
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

const int MaxN = 1200005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

LL f[25][MaxN];
void pre(int n) {
    f[2][1] = 1;
    for (int i = 3; i <= n; ++i)
    for (int m = 1; m < (1 << i - 1); ++m) {
        int mask = m;
        for (int k = 0; k < i - 1; ++k) {
            if (m >> k & 1) {
                f[i][mask] += f[i-1][m];
                f[i][mask] += f[i-1][m ^ (1 << k)];
                int tmp = ((m >> (k + 1)) << k) + (m & ((1 << k) - 1));
                f[i][mask] += f[i-2][tmp];
            }
        }
    }
}
char buf[22];
int main()
{
    //freopen("in","r",stdin);

    pre(20);
    while (scanf("%s", buf) != EOF) {
        int mask = 0;
        int len = strlen(buf);
        for (int i = len - 1; i >= 0; --i) mask = mask * 2 + (buf[i] == '+');
        printf("%lld\n", f[len][mask]);
    }
    
    return 0;
}

// hehe ~

