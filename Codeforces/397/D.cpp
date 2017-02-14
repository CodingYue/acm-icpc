#include <bits/stdc++.h>
using namespace std;

int f[111111];
int g[111111];
int h[111111];

int main(void) {

    int n = 0; scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[f[i]] == 0) {
            g[f[i]] = ++cnt;
            h[cnt] = f[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i] == 0) {
            g[i] = g[f[i]];
        } else {
            if (g[i] != g[f[i]]) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", g[i]);
    }
    puts("");
    for (int i = 1; i <= cnt; ++i) {
        printf("%d ", h[i]);
    }
    puts("");

    return 0;
}