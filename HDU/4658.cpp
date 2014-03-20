// File Name: D.cpp
// Author: YangYue
// Created Time: Thu Aug  8 20:18:17 2013
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
const int MOD = (int) 1e9 + 7;

int n;
int dp[MaxN];
void pre(int n) {
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, r = 1; i - (3*j*j-j) / 2 >= 0; ++j, r *= -1) {
            dp[i] = (dp[i] + dp[i - (3*j*j-j) / 2] * r) % MOD;
            if (i - (3*j*j + j) / 2 >= 0)
                dp[i] = (dp[i] + dp[i - (3*j*j+j) / 2] * r) % MOD;
        }
    }
}
int main()
{
    //freopen("in","r",stdin);

    int n, k;
    int cases; cin >> cases;
    pre(100000);
    while (cases--) {
        scanf("%d%d",&n,&k);
        int ans = -dp[n];
        for (int j = 1, r = 1; n - (3*j*j-j)*k / 2 >= 0; ++j, r *= -1) {
            ans = (ans + dp[n - (3*j*j-j)*k/2] * r) % MOD;
            if (n - (3*j*j+j)*k/2 >= 0) {
                ans = (ans + dp[n - (3*j*j+j)*k/2] * r) % MOD;
            }
        }
        printf("%d\n", (-ans + MOD) % MOD);
    }
    
    return 0;
}

// hehe ~

