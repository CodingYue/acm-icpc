#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int MOD = (int) 1e9 + 7;

const int MaxN = 405;

int m;

int a[MaxN], b[MaxN];
int g[MaxN], k[MaxN][MaxN], ans[MaxN], f[MaxN];
int mat[MaxN][MaxN];
int tmp[MaxN];
bool vis[MaxN];
void mul(int a[], int b[]) {
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= m; ++j) tmp[i+j] = (tmp[i+j] + (LL) a[i] * b[j] % MOD) % MOD;
    for (int i = m; i <= 2 * m - 2; ++i) a[i] = 0;
    for (int i = 0; i < m; ++i) a[i] = tmp[i];
    for (int i = m; i <= 2 * m; ++i) {
        for (int j = 0; j < m; ++j) a[j] = (a[j] + (LL) tmp[i] * mat[i][j] % MOD) % MOD;
    }
    /*
    for (int i = 1; i < m; ++i) tmp[i] = (b[i-1] + (LL) b[m-1] * a[i] % MOD) % MOD;
    tmp[0] = (LL) a[0] * b[m-1] % MOD;
    memcpy(a, tmp, sizeof tmp);
    */
    
}
int main() {
    //freopen("4695.in","r",stdin);
    //freopen("out","w",stdout);

    LL n;
    while (cin >> n) {
        int U, D; 
        scanf("%d", &U);
        for (int i = 1; i <= U; ++i) scanf("%d", a + i);
        scanf("%d", &D);
        m = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= D; ++i) {
            scanf("%d", b + i);
            vis[b[i]] = 1;
            m = max(m, b[i]);
        }

        memset(g, 0, sizeof g);
        g[0] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= U; ++j) if (i - a[j] >= 0) g[i] = (g[i] + g[i-a[j]]) % MOD;    
        
        if (m == 1) {
            printf("%d\n", g[1]);
            continue;
        }
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= m * 2 - 2; ++i)
        for (int j = 1; j <= D; ++j) if (i - b[j] >= 0) f[i] = (f[i] + (LL) f[i-b[j]] * g[b[j]] % MOD) % MOD;
        
        for (int i = 1; i <= m; ++i) if (!vis[i]) g[i] = 0;
        memset(a, 0, sizeof a);
        for (int i = m - 1; i >= 0; --i) a[i] = g[m - i];
        
        memset(mat, 0, sizeof mat);
        mat[0][0] = 1;
        for (int i = 1; i <= m * 2; ++i) {
            for (int j = 1; j < m; ++j) {
                mat[i][j] = (mat[i-1][j-1] + (LL) mat[i-1][m-1] * a[j] % MOD) % MOD;
            }
            mat[i][0] = (LL) a[0] * mat[i-1][m-1] % MOD;
            //for (int j = 0; j < m; ++j) printf("%d ", mat[i][j]); printf("\n");
        }
        
        memset(b, 0, sizeof b);
        b[1] = 1;
        memset(ans, 0, sizeof ans);
        ans[0] = 1;
        for (LL t = n; t; t >>= 1, mul(b, b))
            if (t & 1) mul(ans, b);
        LL res = 0;
        for (int i = 0; i < m; ++i) res = (res + (LL) ans[i] * f[i] % MOD) % MOD;
        cout << res << endl;
    }
    return 0;
}
