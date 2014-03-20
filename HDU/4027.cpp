#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define fi first
#define se second
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double, double> Point;

const int MaxN = 100005;

int n, m;
int Next[MaxN], pre[MaxN];
LL a[MaxN], C[MaxN];
set<int>myset;

#define lowbit(i) (i&-i)
LL sum(int i) {
    LL ret = 0;
    for (; i > 0; i -= lowbit(i))
        ret += C[i];
    return ret;
}
void modify(int i, LL val) {
    for (; i <= n; i += lowbit(i))
        C[i] += val;
}
void read(LL &x) {
    x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
void readint(int &x) {
    x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
void solve() {
    for (int i = 1; i <= n; ++i) C[i] = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        Next[i] = i + 1;
        pre[i] = i - 1;
    }
    myset.clear();
    for (int i = 1; i <= n; ++i) {
        modify(i, a[i]);
        myset.insert(i);
    }
    readint(m);
    while (m--) {
        int k, l, r; readint(k); readint(l); readint(r);
        if (l > r) swap(l, r);
        if (!k) {
            set<int> :: iterator it, L, R;
            L = myset.upper_bound(l - 1);
            R = myset.upper_bound(r);
            for (it = L; it != R;) {
                LL t; t = *it;
                modify(t, -a[t]); a[t] = sqrt(a[t]);
                modify(t, a[t]);
                ++it;
                if (a[t] == 1) myset.erase(t);
            }
        } else {
            printf("%lld\n", sum(r) - sum(l - 1));
        }
    }
}
int main() {
    //freopen("in","r",stdin);
    
    int cnt = 0;
    while (scanf("%d",&n) != EOF) {
        printf("Case #%d:\n", ++cnt);
        solve();
        printf("\n");
    }
    return 0;
}

