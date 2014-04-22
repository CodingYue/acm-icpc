// File Name: C.cpp
// Author: YangYue
// Created Time: Tue Apr 22 20:47:38 2014
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

int n, P;
int C[MaxN];
PII a[MaxN];
vector<int> v[MaxN];
int cnt[MaxN];
void add(int x, int v) {
	++x;
	for (; x <= n + 1; x += lowbit(x)) C[x] += v;
}
int sum(int x) {
	++x;
	int res = 0;
	for (; x > 0; x -= lowbit(x))
		res += C[x];
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d", &n, &P);
	for (int i = 0; i < n; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		a[i] = MP(x, y);
		v[x].push_back(y);
		v[y].push_back(x);
		++cnt[x];
		++cnt[y];
	}
	for (int i = 1; i <= n; ++i) add(cnt[i], 1);

	LL res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			int x = v[i][j];
			add(cnt[x], -1);
			--cnt[x];
			add(cnt[x], 1);
		}
		int need = P - cnt[i];
		int tmp = sum(n) - sum(need - 1);
		tmp -= (cnt[i] >= need);
		res += tmp;
		for (int j = 0; j < v[i].size(); ++j) {
			int x = v[i][j];
			add(cnt[x], -1);
			++cnt[x];
			add(cnt[x], 1);
		}
	}
	cout << res / 2 << endl;
	
	return 0;
}

// hehe ~


