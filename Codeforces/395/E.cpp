#include <bits/stdc++.h>
using namespace std;

const int block_size = 200;

vector<int> edges[111111];

struct Block {
    left_belong[5];
    right_belong[5];
    int count;
} block[block_size];

int K;
int fa[111111];

int get(int *fa, int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa, fa[x]);
}

void solve(Block &block, int l, int r) {
    for (int i = l; i <= r; ++i) fa[i] = i;
    for (int i = l; i <= r; ++i) {
        for (auto v : edges[i]) {
            if (v >= l && v <= r) {
                fa[get(fa, v)] = get(fa, i);
            }
        }
    }
    for (int i = l; i <= r; ++i) {
        if (get(i) == i) block.count++;
    }
    for (int i = 0; i < K; ++i) {
        if (l+i <= r) {
            left_belong[l+i] = get(fa, l+i);
            right_belong[r-i] = get(fa, r-i);
        }
    }
}

Block merge(const Block &a, const Block &b) {
    Block ret;
    ret.count = a.count + b.count;
    for (int i = 0; i < K; ++i) {

    }
}

int main(void) {

    int n; scanf("%d %d", &n, &K);
    int m = 0; scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }


    return 0;
}