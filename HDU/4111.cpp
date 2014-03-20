// File Name: A.cpp
// Author: YangYue
// Created Time: Wed Jun 19 14:25:46 2013
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

int f[55][55005];
int dp(int i, int j) {
    int &res = f[i][j];
    if (res != -1) return res;

    res = 0;
    if (j == 1) return res = dp(i + 1, 0);
    if (j) res |= !dp(i, j - 1);
    if (i) res |= !dp(i - 1, j);
    if (i > 1) {
        if (j) res |= !dp(i - 2, j + 3);
        else res |= !dp(i - 2, 2);
    }
    if (i && j) res |= !dp(i - 1, j + 1);
    return res;
}

int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;

    memset(f, -1, sizeof f);
    for (int cas = 1; cas <= cases; ++cas) {
        printf("Case #%d: ", cas);
        int n; cin >> n;
        int a = 0, b = n - 1;
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if (x == 1) --b, ++a;
            else b += x;
        }
        if (b < 0) b = 0;
        if (dp(a, b)) puts("Alice");
        else puts("Bob");
    }
    
    return 0;
}

// hehe ~

