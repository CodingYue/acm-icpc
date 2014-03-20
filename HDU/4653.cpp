// File Name: K.cpp
// Author: YangYue
// Created Time: Wed Aug  7 15:51:32 2013
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

int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;
    while (cases--) {
        int n, p, k; cin >> p >> n >> k;
        double ans = 1.;
        for (int i = n - k; i <= n; ++i) 
            ans *= (double) i * p / (i * p + 1);
        printf("%.10lf\n", ans);
    }
    
    return 0;
}

// hehe ~

