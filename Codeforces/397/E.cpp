#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> edges[222222];
int degree[222222];

bool vis[222222];

queue<pii> que;
set<pii> Set;

void merge(int u, int len) {
if (Set.find(pii(u, len)) != Set.end()) {
            degree[u]--;
            // printf("Merge u %d, len %d\n", u, len);
            if (degree[u] == 2) {
                // printf("Push u %d, len %d\n", u, len);
                que.push(pii(u, len));
                Set.erase(pii(u, len));
            }
        } else {
            // printf("Insert u %d, len %d\n", u, len);
            Set.insert(pii(u, len));
        }
}

void dfs(int u, int len) {
    if (degree[u] > 2) {
        merge(u, len);
        return;
    }
    vis[u] = true;
    bool isContinued = false;
    for (auto v : edges[u]) {
        if (!vis[v]) {
            dfs(v, len+1);
            isContinued = true;
        }
    }
    if (!isContinued) {
        merge(u, len);
    }
}

int main(void) {

    int n = 0; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            // printf("Push degree = 1, %d\n", i);
            que.push(pii(i, 0));
        }
    }
    
    while (!que.empty()) {
        pii p = que.front(); que.pop();
        int s = p.first;
        int len = p.second;
        dfs(s, len);
    }

    // printf("Set size %d\n", Set.size());
    if (Set.size() > 2) {
        puts("-1");
    } else {
        int ans = 0;
        for (auto p : Set) {
            ans += p.second;
        }
        while (ans % 2 == 0) {
            ans /= 2;
        }
        printf("%d\n", ans);
    }

    return 0;
}