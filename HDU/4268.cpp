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

int n;
multiset <int> tree;
PII A[MaxN], B[MaxN];
void solve() {
    tree.clear();
    scanf("%d",&n);
    
    for (int i = 1; i <= n; ++i) scanf("%d%d",&A[i].fi,&A[i].se);
    for (int i = 1; i <= n; ++i) scanf("%d%d",&B[i].fi,&B[i].se);
    sort(A + 1, A + n + 1);
    sort(B + 1, B + n + 1);
    int a = n, b, ans = 0;
    for (b = n; b >= 1; --b) {
        for (; A[a].fi >= B[b].fi && a >= 1; --a) tree.insert(A[a].se);
        multiset < int > :: iterator x = tree.upper_bound(B[b].se-1);
        if (x != tree.end()) {
            ++ans;
            tree.erase(x);
        }
    }
    printf("%d\n", ans);
}
    
int main() {
    //freopen("in","r",stdin);
    
    int cases; scanf("%d",&cases);
    while (cases--) solve();
    
    return 0;
}

