// File Name: A.cpp
// Author: YangYue
// Created Time: ¶þ  4/16 21:34:02 2013
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

int bit[20], a[20];
bool ok[20][20][1700];
LL f[20][20][1700];
LL dp(int i, int j, int k, bool flag) {

    if (k < 0) return 0;
    if (i == 0) return k == 0;
    if (!flag && ok[i][j][k]) return f[i][j][k];

    LL res = 0;
    for (int digit = (flag ? bit[i] : 9); digit >= 0; --digit) {
        res += dp(i - 1, j, k + (i - j) * digit, flag && (bit[i] == digit));
    }
    if (!flag) {
        ok[i][j][k] = 1;
        f[i][j][k] = res;
    }
    return res;
}
bool check(LL x) {
    if (!x) return 1;
    int len = 0;
    for (LL t = x; t; t /= 10) a[len++] = t % 10;

    for (int i = 0; i < len; ++i) {
        LL l = 0, r = 0;
        for (int j = 0, sum = 0; j < i; ++j) {
            l = l + sum + a[j];
            sum += a[j];
        }
        for (int j = len - 1, sum = 0; j > i; --j) {
            r = r + sum + a[j];
            sum += a[j];
        }
        if (l == r) return 1;
    }
    return 0;
}

LL calc(LL x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    int len = 0;
    for (LL t = x; t; t /= 10) bit[++len] = t % 10;

    memset(ok, 0, sizeof ok);
    memset(f, 0, sizeof f);
    LL res = 0;
    for (int j = 1; j <= len; ++j) {
        res += dp(len, j, 0, 1);
    }
    return res - len + 1;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;
    while (cases--) {
        LL x, y; cin >> x >> y;
        cout << calc(y) - calc(x - 1) << endl;
        //int ans = 0;
        //for (LL t = x; t <= y; ++t) if (check(t)) ++ans;
        //cout << ans << endl;
    }
    
    return 0;
}

// hehe ~

