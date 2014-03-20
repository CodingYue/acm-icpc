// File Name: H.cpp
// Author: YangYue
// Created Time: Fri Mar 15 22:43:24 2013
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
//ym xhm
const int MaxN = 1048590;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n, m;
int f[MaxN];

int main()
{
    //freopen("in","r",stdin);

    while(1)
    {

        scanf("%d",&n);
        if (n < 0) break;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i)
        {
            int x, v; scanf("%d%d",&x,&v);
            f[x] = v;
        }
        for (int k = 0; k < 20; ++k)
        for (int i = 1; i < 1 << 20; ++i)
        {
            if ((i >> k) & 1)
                f[i] += f[i^(1 << k)];
        }
        int ans = 0;
        for (int i = 0; i < 1 << 20; ++i)
            ans = max(ans, f[i]);
        cout << ans << endl;
    }

    return 0;
}

// hehe ~
