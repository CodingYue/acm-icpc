// File Name: quliC.cpp
// Author: YangYue
// Created Time: Fri Apr 11 23:14:35 2014
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

int n, m;
bool used[5];
int a[5][5], b[5][5];
int ans;
bool check() {
	for (int i = 0; i < m; ++i) if (!used[i]) return false;
	return true;
}
void dfs(int k, int now) {
	if (k >= n) {
		if (check()) {
			ans = min(ans, now);
		}
		return;
	}
	for (int i = 0; i < m; ++i) {
		bool tmp = used[i];
		used[i] = 1;
		dfs(k + 1, now + a[k][i]);
		used[i] = tmp;
	}
}

int main()
{
	freopen("in","r",stdin);


	int cases; scanf("%d", &cases);
	int cnt = 0;
	while (cases--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &b[i][j]);
		if (n < m) {
			for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) a[j][i] = b[i][j];
			swap(n, m);
		} else {
			for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) a[i][j] = b[i][j];
		}
		memset(used, 0, sizeof used);
		ans = INF;
		dfs(0, 0);
		if (ans == INF) while(1);
		printf("Case %d: %d\n", ++cnt, ans);
	}
	
	return 0;
}

// hehe ~


