// File Name: Asmall.cpp
// Author: YangYue
// Created Time: Sat Jun 14 22:22:32 2014
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

LL sum[MaxN];

int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		int n;
		LL p, q, r, s;
		cin >> n >> p >> q >> r >> s;
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1] + ((p * (i - 1) + q) % r + s);
		}
		LL ans = 0;
		/*
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				LL tans =  sum[n] - sum[j] + sum[i-1];
				tans = min(tans, sum[n] - sum[i-1]);
				tans = min(tans, sum[j]);
				ans = max(ans, tans);
			}
		}
		*/
		sum[n+1] = sum[n];
		
		for (int i = 1; i <= n; ++i) {
			int l = i, r = n + 1;
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (sum[mid] - sum[i-1] <= sum[n] - sum[mid]) {
					l = mid;
				} else r = mid;
			}
			LL tmp = max(sum[i-1], max(sum[l] - sum[i-1], sum[n] - sum[l]));
			ans = max(ans, sum[n] - tmp);
			tmp = max(sum[i-1], max(sum[r] - sum[i-1], sum[n] - sum[r]));
			ans = max(ans, sum[n] - tmp);
		}
		
		printf("Case #%d: %.12lf\n", cas, ans / (double) sum[n]);
	}
	
	return 0;
}

// hehe ~


