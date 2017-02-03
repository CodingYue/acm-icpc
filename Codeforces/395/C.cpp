#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int mod;

int fpow(int a, int t{
    int res = 1;
    for (; t; t >>= 1, a = (long long) a * a % mod) {
        if (t & 1) res = (long long) res * a % mod;
    }
    return res;
}

int inverse(int x) {
    return fpow(x, mod-2);
}

bool isPossible(int x, int d) [
    
]

int main(void) {

    int n; scanf("%d", &mod, &n);

    int sum = 0;

    set<int> SET;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        SET.insert(a[i]);
        sum = (sum + a[i]) % m;
    }

    vector<int> possible_d;
    for (int i = 0; i < n; ++i) {
        int left = (sum - (long long) n * a[i] % mod + mod) % mod;
        left = left * 2 % mod;
        int x = (long long) n * (n-1) % mod;
        int d = (long long) left * inverse(x) % mod;
        if (isPossible(a[i], d)) possible_d.push_back(d);
    }

    return 0;
}