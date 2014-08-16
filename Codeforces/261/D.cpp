// File Name: D.cpp
// Author: YangYue
// Created Time: Sat Aug 16 00:01:33 2014
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
int f[MaxN];
int a[MaxN];
int C[MaxN];
void add(int x, int v) {
	for (; x <= n; x += lowbit(x)) C[x] += v;
}
int ask(int x) {
	int res = 0;
	for (; x > 0; x -= lowbit(x)) res += C[x];
	return res;
}
int main()
{
	freopen("in","r",stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);

	map<int, int> cnt;
	for (int i = n; i >= 1; --i) {
		++cnt[a[i]];
		f[i] = cnt[a[i]];
		add(f[i], 1);
	}
	cnt.clear();
	LL res = 0;
	for (int i = 1; i <=n; ++i) {
		cnt[a[i]]++;
		int x = cnt[a[i]];
		add(f[i], -1);
		res += ask(x - 1);
	}
	cout << res << endl;
	
	return 0;
}

// hehe ~


