// File Name: hdu4352.cpp
// Author: YangYue
// Created Time: Wed Aug 14 12:51:27 2013
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

LL f[20][1 << 11][20];
LL bits[20];
LL dp(int len, bool limit, int mask, int lis, bool first) {
    if (lis < 0) return 0;
    if (len == 0) return lis == 0;
    LL res = f[len][mask][lis];
    if (!limit && res != -1) return res;
    res = 0;
    int up = !limit ? 9 : bits[len];
    int a[10], s = 0;
    for (int t = 0; t < 10; ++t) if (mask >> t & 1) a[s++] = t;
    for (int i = first; i <= up; ++i) {
        int t;
        for (t = s - 1; t >= 0; --t) if (a[t] < i) break;
        int Nextmask = 0;
        if (t + 1 != s) 
            Nextmask = mask ^ (1 << a[t + 1]) ^ (1 << i);
        else Nextmask = mask ^ (1 << i);
        res += dp(len - 1, limit & (i == up), Nextmask, lis - (t + 1 == s), 0);
    }
    if (!limit) f[len][mask][lis] = res;
    return res;
}
LL get(LL x, int K) {
    if (x <= 0) return 0;
    int len = 0;
    memset(bits, 0, sizeof bits);
    for (LL t = x; t; t /= 10) bits[++len] = t % 10;
    LL res = dp(len, 1, 0, K, 1);
    for (int i = 1; i < len; ++i) res += dp(i, 0, 0, K, 1);
    return res;
}
int check(int x) {
    int len = 0;
    for (int t = x; t; t /= 10) bits[++len] = t % 10;
    reverse(bits + 1, bits + len + 1);
    int f[10];
    for (int i = 1; i <= len; ++i) f[i] = 1;
    int ans = 0;
    for (int i = 2; i <= len; ++i) {
        int tmp = 0;
        for (int j = 1; j < i; ++j) if (bits[j] < bits[i]) tmp = max(tmp, f[j]);
        f[i] = tmp + 1;
        ans = max(ans, f[i]);
    }
    return ans;
}
int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;
    int cas = 0;
    memset(f, -1, sizeof f);
    while (cases--) {
        int K;
        LL l, r; scanf("%lld%lld%d", &l, &r, &K);
        if (l > r) swap(l, r);
        //int ans = 0;
        //for (int i = l; i <= r; ++i) if (check(i) == K) ++ans;
        printf("Case #%d: ", ++cas);
    //    printf("%d ", ans);
        printf("%lld\n", get(r, K) - get(l - 1, K));
    }
    
    return 0;
}

// hehe ~

