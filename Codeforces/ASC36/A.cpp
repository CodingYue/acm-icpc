// File Name: A.cpp
// Author: YangYue
// Created Time: Mon Oct  6 10:31:24 2014
//headers 
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

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int color[MaxN];
int a[MaxN];
bool vis[MaxN];
vector<int> edges[MaxN];

int justify(int x) {
	if (x > 2*n) x -= 2*n;
	return x;
}
int DFN[MaxN], Low[MaxN];
int TimeIdx, top;
int Stack[MaxN];
bool instack[MaxN];
int SCC[MaxN];
int pos[MaxN];
int cntSCC;
vector<int> contains[MaxN];
void tarjan(int u) {
	Low[u] = DFN[u] = ++TimeIdx;
	Stack[++top] = u;
	instack[u] = true;
	for (auto v : edges[u]) {
		if (!DFN[v]) {
			tarjan(v);
			Low[u] = min(Low[u], Low[v]);
		} else if (instack[v]) Low[u] = min(Low[u], DFN[v]);
	}
	if (Low[u] == DFN[u]) {
		++cntSCC;
		int v = 0;
		do {
			v = Stack[top--];
			instack[v] = false;
			SCC[v] = cntSCC;
			contains[cntSCC].push_back(v);
		} while (u != v);
	}
}
int choice[MaxN];
int ans[MaxN];
int main()
{
	freopen("chip.in","r",stdin);
	freopen("chip.out","w",stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", color + i);
		color[i+n] = color[i];
	}
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", a+i);
		if (vis[a[i]]) {
			a[i] += n;
		}
		vis[a[i]] = true;
		pos[a[i]] = i;
	}
	int m = 2*n;
	for (int i = 0; i < m; ++i) {
		int pre = a[(i-1+m)%m];
		int now = a[i];
		if (color[pre] == color[now]) {
			edges[now].push_back(justify(pre+n));
		}
		int nex = a[(i+1)%m];
		if (color[nex] == color[now]) {
			edges[now].push_back(justify(nex+n));
		}
	}
	/*
	for (int i = 1; i <= m; ++i)
		for (auto j : edges[i]) printf("%d->%d\n", i, j);
		*/
	for (int i = 1; i <= m; ++i) if (!DFN[i]) tarjan(i);

	for (int i = 1; i <= n; ++i) if (SCC[i] == SCC[i+n]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	
	for (int i = 1; i <= n; ++i) {
		printf("%d ", 1 + (SCC[i] < SCC[i+n] ? pos[i] : pos[i+n]));
	}
	
	return 0;
}

// hehe ~


