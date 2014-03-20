// File Name: hdu4626.cpp
// Author: YangYue
// Created Time: Sun Oct  6 16:36:27 2013
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
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

char s[MaxN];
int cnt[MaxN];
int f[50];

int main()
{
    //freopen("in","r",stdin);

    int cases; scanf("%d", &cases);
    while (cases--) {
        scanf("%s", s); int len = strlen(s);
        memset(cnt, 0, sizeof cnt);
        int x = 0;
        ++cnt[0];
        for (int i = 0; i < len; ++i) {
            int t = s[i] - 'a';
            x ^= (1 << t);
            ++cnt[x];
        }
        int n = 20;
        for (int j = 0; j < n; ++j)
        for (int i = 0; i < 1 << n; ++i) if (i >> j & 1)
            cnt[i] += cnt[i ^ (1 << j)];
        int Q; scanf("%d", &Q);
        while (Q--) {
            int k; scanf("%d", &k);
            int s = (1 << n) - 1;
            int num[5];
            memset(f, 0, sizeof f);
            for (int i = 0; i < k; ++i) {
                char cc[2]; scanf("%s", cc);
                num[i] = cc[0] - 'a';
            }
            sort(num, num + k); k = unique(num, num + k) - num;
            for (int i = 0; i < k; ++i) s ^= 1 << num[i];
            for (int t = 0; t < 1 << k; ++t) {
                int now = s;
                for (int i = 0; i < k; ++i) if (t >> i & 1) now |= 1 << num[i];
                f[t] = cnt[now];
            }
            long long ans = 0;
            for (int t = 0; t < 1 << k; ++t) {
                int res = 0;
                for (int x = t; x >= 0; x = (x - 1) & t) {
                    //printf("%d %d\n", x^t, __builtin_popcount(x ^ t));
                    int tmp = __builtin_popcount(x ^ t);
                    if (tmp & 1) res -= f[x];
                    else res += f[x];
                    if (x == 0) break;
                }
                ans += (LL) res * (res - 1) / 2;
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}

// hehe ~

