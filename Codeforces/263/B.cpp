// File Name: B.cpp
// Author: YangYue
// Created Time: Tue Aug 26 22:14:35 2014
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
const int mod = (int) 1e9 + 7;

int n;
int color[MaxN];
vector<int> edges[MaxN];
LL f[MaxN][2];
LL tmp[MaxN][2];
bool vis[MaxN];
void dfs(int u) {
	vector<int> sons;
	for (auto v : edges[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		dfs(v);
		sons.push_back(v);
	}
	for (int i = 0; i <= sons.size(); ++i) tmp[i][0] = tmp[i][1] = 0;

	if (color[u] == 1) tmp[0][1] = 1;
	else tmp[0][0] = 1;

	for (int i = 0; i < sons.size(); ++i) {
		int v = sons[i];
		tmp[i+1][1] = (tmp[i+1][1] + tmp[i][0] * f[v][1] % mod) % mod;
		tmp[i+1][1] = (tmp[i+1][1] + tmp[i][1] * (f[v][0] + f[v][1]) % mod) % mod;
		tmp[i+1][0] = (tmp[i+1][0] + tmp[i][0] * (f[v][0] + f[v][1]) % mod) % mod;
	}
	f[u][0] = tmp[sons.size()][0];
	f[u][1] = tmp[sons.size()][1];
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x; scanf("%d", &x);
		edges[x].push_back(i);
		edges[i].push_back(x);
	}
	for (int i = 0; i < n; ++i) scanf("%d", color + i);
	vis[0] = 1; dfs(0);
	printf("%d\n", (int) f[0][1]);
	
	return 0;
}

// hehe ~


