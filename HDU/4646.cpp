// File Name: D.cpp
// Author: YangYue
// Created Time: Wed Aug  7 12:24:19 2013
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

const int MaxN = 205;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int tot, n, m, ans;
int a[MaxN];

void deco(int n) {
    tot = 0;
    for (int d = 2; d * d <= n; ++d) if (n % d == 0) {
        a[tot++] = d;
        while (n % d == 0) n /= d;
    }
    if (n > 1) a[tot++] = n;
}
int calc(int d) {
    int c = (d % 3) * (m % 3) % 3 * d;
    if (n < c) return 0;
    int r = n - c;
    return r / 3 / d + 1;
}
void dfs(int dep, int d, int miu) {
    if (dep == tot) {
        ans += calc(d) * miu;
        return;
    }
    dfs(dep + 1, d, miu);
    dfs(dep + 1, d * a[dep], miu * -1);
}
int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;
    while (cases--) {
        scanf("%d", &n);
        if (n % 2 == 0 || n % 3 == 0) {
            puts("0");
            continue;
        }
        m = n;
        n = n / 2 + 2;
        deco(n);
        ans = 0;
        dfs(0, 1, 1);
        printf("%d\n", ans);
    }

    return 0;
}

// hehe ~

