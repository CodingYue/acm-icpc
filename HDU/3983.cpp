// File Name: B.cpp
// Author: YangYue
// Created Time: Fri Mar 15 19:34:16 2013
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
const int MaxN = 262150;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int Q;
int C[20][MaxN];
multiset < LL > SET;

void update(int *C, int i, int v, int n)
{
    for (; i <= n; i += lowbit(i)) C[i] += v;
}
int query(int *C, int i)
{
    int rt = 0;
    for (; i; i -= lowbit(i)) rt += C[i];
    return rt;
}

int main()
{
    //freopen("in","r",stdin);

    int cases, cnt = 0; cin >> cases;
    while (cases--)
    {
        cin >> Q;
        SET.clear();
        LL val = 0;
    
        for (int i = 1; i <= 18; ++i)
        for (int j = 1; j <= 1 << i; ++j) C[i][j] = 0;
        
        printf("Case %d:\n", ++cnt);
        while (Q--)
        {
            char s[10]; LL x; scanf("%s %lld",s, &x);
            if (s[0] == 'I')
            {
                SET.insert(x - val);
                for (int i = 1; i <= 18; ++i)
                {
                    int n = 1 << i;
                    LL tmp = x - val; tmp = (tmp % n + n) % n;
                    update(C[i], tmp + 1, 1, n);
                }
            } else
            if (s[0] == 'D')
            {
                int t = SET.count(x - val);
                if (!t) puts("Del error"); 
                else
                {
                    SET.erase(x - val);
                    for (int i = 1; i <= 18; ++i)
                    {
                        int n = 1 << i;
                        LL tmp = ((x - val) % n + n) % n;
                        update(C[i], tmp + 1, -t, n);
                    }
                }
            } else
            if (s[0] == 'A')
            {
                val += x;
            } else
            if (s[0] == 'S')
            {
                if (!SET.empty() && *SET.begin() + val - x < 0) puts("Sub error");
                else if (!SET.empty()) val -= x;
            } else
            if (s[1] == 'B')
            {
                ++x;
                int n = 1 << x;
                LL l = 1 << (x - 1), r = (1 << x) - 1;
                l = ((l - val) % n + n) % n;
                r = ((r - val) % n + n) % n;
                if (l <= r) printf("%d\n", query(C[x], r + 1) - query(C[x], l));
                else
                {
                    int ans = query(C[x], n) - query(C[x], l) + query(C[x], r + 1);
                    printf("%d\n", ans);
                }
            } else
            {
                int ans = SET.count(x - val);
                printf("%d\n", ans);
            }
        }
        printf("\n");
    }

    
    return 0;
}

// hehe ~
