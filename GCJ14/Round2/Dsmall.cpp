// File Name: Dsmall.cpp
// Author: YangYue
// Created Time: Sat May 31 23:24:55 2014
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

string str[1005];
int n, m;
int worst = 0;
int res = 0;
int choose[1005];
bool yes[5];
int solve() {
	vector<string> v[10];
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int t = choose[i];
		int Max = 0;
		for (int j = 0; j < (int) v[t].size(); ++j) {
			int cnt = 0;
			for (int k = 0; k < min(str[i].size(), v[t][j].size()); ++k) {
				if (str[i][k] != v[t][j][k]) break;
				++cnt;
			}
			Max = max(Max, cnt);
		}
		res += str[i].size() - Max;
		v[t].push_back(str[i]);
	}
	return res;
}
void dfs(int k) {
	if (k >= n) {
		memset(yes, 0, sizeof yes);
		for (int i = 0; i < n; ++i) yes[choose[i]] = 1;
		for (int i = 0; i < m; ++i) if (!yes[i]) return;
		int tmp = solve();
		if (tmp > worst) {
			worst = tmp;
			res = 1;
		} else 
		if (worst == tmp) {
			res++;
		}
		return;
	}
	for (int i = 0; i < m; ++i) {
		choose[k] = i;
		dfs(k + 1);
	}
}
int main()
{
	freopen("in","r",stdin);

	int cases = 0; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		worst = 0;
		res = 0;
		printf("Case #%d: ", cas);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
		}
		dfs(0);
		printf("%d %d\n", worst + m, res);
	}
	
	return 0;
}

// hehe ~


