#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))

const int MaxN = 1005;
const int INF = 0x3f3f3f3f;

int n, m;
int match[MaxN];
bool yes[MaxN];
bool vis[MaxN];
bool MAP[MaxN][MaxN];

int dfs(int u) {
    for (int v = 1; v <= m; ++v) if (MAP[u][v] && !vis[v]) {
        vis[v] = 1;
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int et;
struct Edge {
    int v; Edge *Next;
    Edge(){}
    Edge(int v, Edge *Next)
        : v(v), Next(Next) {}
} *g[MaxN * 2], edge[MaxN * MaxN];
void ins(int u, int v) {
    edge[et] = Edge(v, g[u]); g[u] = &edge[et++];
}
int belong[MaxN];
int dfn[MaxN], low[MaxN], Tim, top, cnt;
int stack[MaxN];
bool instack[MaxN];
void tarjan(int u) {
    dfn[u] = low[u] = ++Tim; stack[++top] = u; instack[u] = 1;
    for (Edge *p = g[u]; p; p = p->Next) {
        if (!dfn[p->v]) {
            tarjan(p->v);
            low[u] = min(low[u], low[p->v]);
        } else if (instack[p->v]) low[u] = min(low[u], dfn[p->v]);
    }
    if (dfn[u] == low[u]) {
        ++cnt;
        while (instack[u]) {
            belong[stack[top]] = cnt;
            instack[stack[top]] = 0;
            --top;
        }
    }
}
int main() {
    //freopen("in","r",stdin);
    
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        printf("Case #%d:\n", cas);
        memset(MAP, 0, sizeof MAP);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                int v; scanf("%d", &v);
                MAP[i][v] = 1;
            }
        }
        memset(match, -1, sizeof match);
        int ans = 0;
        for (int u = 1; u <= n; ++u) {
            memset(vis, 0, sizeof vis);
            yes[u] = dfs(u);
            ans += yes[u];
        }
        et = 0;
        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) if (MAP[i][j]) {
            if (match[j] == i) {
                ins(j + n, i);
                ins(i, j + n);
            }
            else ins(i, j + n);
        }
        int S = 0, T = n + m + 1;
        for (int i = 1; i <= n; ++i) {
            if (yes[i]) ins(i, S); else ins(S, i);
        }
        for (int i = 1; i <= m; ++i) {
            if (match[i] == -1)    ins(i + n, T);
            else ins(T, i + n);
        }
        
        memset(dfn, 0,sizeof dfn);
        memset(instack, 0, sizeof instack);
        Tim = top = cnt = 0;
        
        for (int i = 1; i < T; ++i) if (!dfn[i]) tarjan(i);
        
    //    for (int i = 0; i <= n + m + 1; ++i) printf("%d ", belong[i]); printf("\n");
        
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            res.clear();
            for (int j = 1; j <= m; ++j) if (MAP[i][j] && (belong[i] == belong[j + n]))
                res.push_back(j);
            printf("%d", (int) res.size());
            for (int j = 0; j < res.size(); ++j) printf(" %d", res[j]);
            printf("\n");
        }
            
    }
    //while(1);
    
    return 0;
}
