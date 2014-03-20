// File Name: hdu3802.cpp
// Author: YangYue
// Created Time: Èý  4/ 3 15:19:58 2013
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

LL a, b, n;
int mod;
LL base[2][2], vect[2][2], ans[2][2], tmp[2][2];
LL fpow(LL a, LL t, int mod) {
    LL res = 1;
    for (; t; t >>= 1, a = a * a % mod)
        if (t & 1) res = res * a % mod;
    return res;
}
void mul(LL a[2][2], LL b[2][2], int mod) {
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
    }
    memcpy(a, tmp, sizeof tmp);
}
int main()
{
    //freopen("in","r",stdin);

    int cases; cin >> cases;
    while (cases--) {

        cin >> a >> b >> n >> mod;
        
        memset(ans, 0, sizeof ans);
        memset(vect, 0, sizeof vect);
        memset(base, 0, sizeof base);
        base[0][0] = base[0][1] = 1;
        base[1][0] = 1; base[1][1] = 0;
        vect[0][0] = 1;
        ans[0][0] = ans[1][1] = 1;
        for (int t = n; t; t >>= 1, mul(base, base, mod - 1))
            if (t & 1) mul(ans, base, mod - 1);
        mul(vect, ans, mod - 1);

        int fib = vect[0][0];
    //    cout << fib << endl;

        memset(base, 0, sizeof base);
        base[0][0] = 2 * (a + b) % mod;
        base[1][0] = -(a - b) * (a - b) % mod; base[1][0] = (base[1][0] + mod) % mod;
        base[0][1] = 1;
        base[1][1] = 0;
        memset(ans, 0, sizeof ans);
        memset(vect, 0, sizeof vect);
        vect[0][0] = 2 * (a + b) % mod;
        vect[0][1] = 2;
        ans[0][0] = ans[1][1] = 1;
        for (int t = fib - 1; t; t >>= 1, mul(base, base, mod))
            if (t & 1) mul(ans, base, mod);
        mul(vect, ans, mod);

        LL A = fpow(a, (mod - 1) / 2, mod),
           B = fpow(b, (mod - 1) / 2, mod);
        LL ans = (A + 1) * (B + 1) % mod;
        //cout << vect[0][0] << endl;
        cout << ans * vect[0][0] % mod << endl;
    }

}

// hehe ~

