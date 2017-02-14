#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int k, a, b; scanf("%d %d %d", &k, &a, &b);

    int set_a = a / k;
    int set_b = b / k;

    if (set_a == 0 && b % k > 0) {
        puts("-1");
        return 0;
    }
    if (set_b == 0 && a % k > 0) {
        puts("-1");
        return 0;
    }

    printf("%d\n", set_a + set_b);

    return 0;
}