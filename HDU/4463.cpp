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
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef unsigned long long ULL;
#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define MP make_pair

const int MaxN = 5005;

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w)
        : u(u), v(v), w(w) {}
    bool operator < (const Edge &b) const {
        return w < b.w;
    }
} edge[MaxN];
int n, m, A, B;
int fa[MaxN];
PII p[MaxN];

int dis(PII A, PII B) {
    return sqr(A.first - B.first) + sqr(A.second - B.second);
}
int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
int main() {
    //freopen("input.txt","r",stdin);

    while (scanf("%d",&n),n) {
        m = 0;
        scanf("%d%d",&A,&B);
        for (int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d",&x,&y);
            p[i] = MP(x, y);
            fa[i] = i;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                edge[m++] = Edge(i, j, dis(p[i], p[j]));
        sort(edge, edge + m);
        fa[get(A)] = get(B);
        double ans = sqrt((double)dis(p[A], p[B]));
        int t = 1;
        for (int i = 0; i < m; ++i)
            if (get(edge[i].u) != get(edge[i].v)) {
                fa[get(edge[i].u)] = get(edge[i].v);
                ans += sqrt((double)edge[i].w);
                ++t;
                if (t == n - 1) break;
            }
        printf("%.2lf\n", ans);
    }
    return 0;
}
