#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 400005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n, et, top;
LL fr[MaxN], p[MaxN], r[MaxN];
int stack[MaxN];
LL sum[MaxN], f[MaxN];
bool vis[MaxN];
struct Edge {
    int v; Edge *Next;
    Edge(){}
    Edge(int v, Edge *Next)
        : v(v), Next(Next) {}
} *g[MaxN], edge[MaxN * 2];
void ins(int u, int v) {
    edge[et] = Edge(v, g[u]); g[u] = &edge[et++];
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

LL calc(int x, LL k) {
    return f[x] - sum[x] * k;
}
LL query(LL k) {
    int l = 0, r = top;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        int a = stack[mid];
        int b = stack[mid + 1];
        LL y = f[b] - f[a];
        LL x = sum[b] - sum[a];
        if (y > k * x) r = mid; else l = mid;
    }
    return min(calc(stack[l], k), calc(stack[r], k));
}
bool check(int i, int j, int k) {
    LL x1 = sum[j] - sum[i];
    LL y1 = f[j] - f[i];
    LL x2 = sum[k] - sum[i];
    LL y2 = f[k] - f[i];
    return (long double) y2 / x2  > (long double) y1 / x1;
    //return x1 * y2 - x2 * y1 > 0;
}
int find(int i) {
    int l = 1, r = top;
    if (l == r || check(stack[top-1], stack[top], i)) return r;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (!check(stack[mid-1], stack[mid], i)) r = mid; else l = mid;
    }
    return l;
}
void dfs(int u) {

    f[u] = query(p[u]) + r[u] + sum[u] * p[u];

    int tmptop = top;
    int tail = 0;
    top = find(u);
    tail = top + 1;
    int tmp = stack[tail];
    stack[++top] = u;

    for (Edge *p = g[u]; p; p = p->Next) if (!vis[p->v]) {
        sum[p->v] = sum[u] + fr[p->v];
        vis[p->v] = 1;
        dfs(p->v);
    }

    stack[tail] = tmp;
    top = tmptop;
}
// f[i] = min{ f[j] + p[i] * (sum[i] - sum[j]) + r[i])
// f[i] = min{ f[j] - p[i] * sum[j] } + r[i] + p[i] * sum[i];
void gen(int &n) {
    n = 1000;
    int lim = 1000;
    for (int i = 1; i <= n; ++i) {
        fr[i] = rand() % lim + 1;
        p[i] = rand() % lim + 1;
        r[i] = rand() % lim + 1;
    }
}
/*
LL force(int n) {
    LL F[1001] = {0};
    f[1] = 0;
}
*/
int mmain()
{
    //freopen("in","r",stdin);


    int cases; readint(cases);
    for (int cas = 1; cas <= cases; ++cas) {
        printf("Case #%d: ", cas);

        //gen(n);
        readint(n);
        
        for (int i = 1; i <= n; ++i) {
            read(fr[i]); read(p[i]); read(r[i]);
        }
        
        et = 0; memset(g, 0, sizeof(g));
        for (int i = 1; i < n; ++i) {
            int u = i, v = i + 1; 
            readint(u); readint(v);
            ins(u, v); ins(v, u);
        }
        sum[1] = fr[1];
        memset(vis, 0, sizeof vis);
        stack[top = 1] = 0;
        vis[1] = 1; dfs(1);
        LL ans = 0;
        for (int i = 2; i <= n; ++i) ans += f[i];
        printf("%lld\n", ans);
        //force(n);
    //    break;
    }

    return 0;
}

int main() {
    
    
    char* SysStack = NULL;
    char* MyStack = new char[33554432];
    MyStack += 33554432 - 1048576;
    __asm__(
        "movl %%esp,%%eax\n\t"
        "movl %1,%%esp\n\t"
        :"=a"(SysStack)
        :"m"(MyStack)
    );

    mmain();
    
    
    __asm__(
        "movl %0,%%esp\n\t"
        ::"m"(SysStack)
    );
    
    
    return 0;
}
