#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int color[111111];
pair<int, int> edges[111111];
pair<int, int> choose[111111];

int main(void) {
    int n = 0; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        edges[i] = pii(u, v);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &color[i]); 
    }
    
    int total = 0;
    for (int i = 1; i < n; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (color[u] != color[v]) {
            choose[total++] = pii(u, v);
        }
    }
    // for (int i = 0; i < total; ++i) {
    //     printf("%d %d\n", choose[i].first, choose[i].second);
    // }
    int x = -1;
    if (total >= 2) {
        if (choose[0].first == choose[1].first) {
            x = choose[0].first;
        } else if (choose[0].first == choose[1].second) {
            x = choose[0].first;
        } else if (choose[0].second == choose[1].first) {
            x = choose[0].second;
        } else if (choose[0].second == choose[1].second) {
            x = choose[0].second;
        }
        for (int i = 0; i < total; ++i) {
            if (choose[i].first == x || choose[i].second == x) {
                continue;
            }
            x = -1;
            break;
        }
        if (x == -1) {
            puts("NO");
            return 0;
        } 
    } else if (total == 1) {
        x = choose[0].first;
    } else {
        x = 1;
    }
    puts("YES");
    printf("%d\n", x);
}