// File Name: mutF.cpp
// Author: YangYue
// Created Time: Fri Aug 23 20:01:08 2013
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

const int MaxN = 1000005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
LL f[MaxN], S[MaxN];

int main()
{
    //freopen("in","r",stdin);

    int A, B;
    while (cin >> n >> A >> B) {
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            S[i] = S[i-1] + x;
        }
        LL best = LINF;
        f[n] = LINF;
        best = S[n];
        for (int i = n - 1; i >= 0; --i) {
            f[i] = S[n];
            f[i] = min(f[i], best);
            best = min(best, max(S[i], A + B - f[i] + S[i] + 1));
        }
        if (f[0] <= A) puts("ALICE");
        else puts("BOB");
    }
    
    return 0;
}

// hehe ~

