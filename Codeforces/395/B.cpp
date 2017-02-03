#include <bits/stdc++.h>
using namespace std;

int ans[555555];

int main(void) {

    int n = 0; scanf("%d", &n);

    puts("YES");

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 = (x1 % 2 + 2) % 2;
        y1 = (y1 % 2 + 2) % 2;
        printf("%d\n", x1 * 2 + y1 + 1);
    }
    

    return 0;
}