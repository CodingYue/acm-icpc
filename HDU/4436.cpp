#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef unsigned long long ULL;
#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define fi first
#define se second
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))

const int MaxN = 300005;
const int MOD = 2012;

int T, n, tot, ans;
int f[MaxN], cnt[MaxN], times[MaxN];
char s[MaxN];
struct sanode {
    int ml, idx;
    sanode *fa, *ch[10];
} *tail, *root, arr[MaxN], *qu[MaxN];
//Add
void clear() {
    memset(arr, 0, sizeof(arr));
    memset(f, 0, sizeof(f));
    memset(times, 0, sizeof(times));
    memset(cnt, 0, sizeof(cnt));
    tail = root = NULL;
    tot = 0;
}
void Add(char c, int len) {
    int x = c - '0'; // ! need changes !!
    sanode *p = tail, *np = &arr[tot++];
    np->ml = len; np->idx = tot - 1;
    for (; p && !p->ch[x]; p = p->fa) p->ch[x] = np;
    tail = np;
    if (!p) np->fa = root;
    else if (p->ml + 1 == p->ch[x]->ml) np->fa = p->ch[x];
    else {
        sanode *q = p->ch[x], *r = &arr[tot++];
        *r = *q; r->ml = p->ml + 1;
        r->idx = tot - 1;
        q->fa = np->fa = r;
        for (; p && p->ch[x] == q; p = p->fa) p->ch[x] = r;
    }
}
void solve() {
    root = &arr[tot++];
    while (T--) {
        scanf("%s",s); n = strlen(s);
        tail = root;
        for (int i = 0; i < n; ++i) Add(s[i], i + 1);
    }
    for (int i = 0; i < tot; ++i) cnt[arr[i].ml]++;
    for (int i = 1; i < tot; ++i) cnt[i] += cnt[i-1];
    for (int i = 0; i < tot; ++i) qu[--cnt[arr[i].ml]] = &arr[i];

    int t = -1;
    ans = 0;
    if (root->ch[0]) t = root->ch[0]->idx;
    times[0] = 1;
    for (int i = 0; i < tot; ++i) {
        int u = qu[i]->idx;
        ans = (ans + f[u]) % MOD;
        sanode *p = qu[i];
        for (int c = 0; c < 10; ++c)
            if (p->ch[c]) {
                int v = p->ch[c]->idx;
                if (v != t || i) {
                    times[v] = (times[u] + times[v]) % MOD;
                    f[v] = (f[v] + f[u] * 10 + times[u] * c) % MOD;
                }
            }
    }

    printf("%d\n", ans);
}

int main() {
    //freopen("input.txt","r",stdin);

    while (scanf("%d\n",&T) != EOF) {
        clear();
        solve();
    }

    return 0;
}
