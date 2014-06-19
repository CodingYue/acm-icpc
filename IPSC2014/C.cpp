// File Name: C.cpp
// Author: YangYue
// Created Time: Sun Jun 15 19:16:28 2014
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

const int MaxN = 100005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int a[MaxN];

int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	while (cases--) {
		set<int> cnt;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		vector<int> res;
		/*
		for (int i = 0; i < n; ++i) printf("%d ", cnt[a[i]]);
		puts("");
		*/
		for (int i = 0; i < n; ++i) {
			if (!cnt.count(a[i])) {
				cnt.insert(a[i]);
				res.push_back(a[i]);
			}
		}
		for (int i = 0; i < res.size(); ++i) 
			printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ');
	}
	
	return 0;
}

// hehe ~


