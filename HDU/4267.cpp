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

const int MaxN = 50005;

int n, Q, tot;
int A[MaxN];
struct TreeN {
    int add, l, r;
    TreeN *lc, *rc;
} *root[15][15], arr[MaxN * 40];
void modify(TreeN *x, int i, int j, int val) {
    int l, r; l = x->l; r = x->r;
    if (i == l && j == r) {
        x->add += val;
        return;
    }
    int mid = l + r >> 1;
    if (j <= mid) modify(x->lc, i, j, val);
    else if (i > mid) modify(x->rc, i, j, val);
    else {
        modify(x->lc, i, mid, val);
        modify(x->rc, mid + 1, j, val);
    }
}
int query(TreeN *x, int pos) {
    int l, r; l = x->l; r = x->r;
    if (l == r) return x->add;
    int mid = l + r >> 1;
    if (pos <= mid) return query(x->lc, pos) + x->add;
    else return query(x->rc, pos) + x->add;
}
TreeN *newNode(int l, int r) {
    TreeN *x = &arr[tot++];
    x->l = l, x->r = r; x->add = 0;
    x->lc = x->rc = NULL;
    return x;
}
void build(TreeN *&x, int l, int r) {
    x = newNode(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(x->lc, l, mid);
    build(x->rc, mid + 1, r);
}
void solve() {
    tot = 0;
    for (int i = 0; i < n; ++i) scanf("%d",A+i);
    for (int i = 1; i <= 10; ++i)
    for (int j = 0; j < i; ++j)
        build(root[i][j], 0, (n - 1 - j) / i);
    scanf("%d",&Q);
    while (Q--) {
        int op; scanf("%d",&op);
            int a, b, k, c, t;
        if (op == 1) {
            scanf("%d%d%d%d",&a,&b,&k,&c); --a; --b;
            t = (b - a) / k; b = a % k;
            modify(root[k][b], (a - b) / k, (a - b) / k + t, c);
        } else {
            scanf("%d",&a); t = 0; --a;
            for (int i = 1; i <= 10; ++i) {
                c = a % i;
                t += query(root[i][c], (a - c) / i);
            }
            printf("%d\n", t + A[a]);
        }
    }
}
int main() {
    //freopen("in","r",stdin);
    
    while (scanf("%d",&n) != EOF) solve();
    
    return 0;
}
    


