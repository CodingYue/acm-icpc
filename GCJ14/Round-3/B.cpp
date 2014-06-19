// File Name: B.cpp
// Author: YangYue
// Created Time: Sat Jun 14 23:02:16 2014
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


int f[205][2005];
int H[205], G[205];
void update(int &x, int v) {
	if (x == -1) x = v;
	else x = max(x, v);
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		int P, Q, n;
		scanf("%d %d %d", &P, &Q, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", H + i, G + i);
		}
		/*
		if (cas == 77) {
			printf("Here\n");
			printf("%d %d %d\n", P, Q, n);
			for (int i = 0; i < n; ++i) printf("%d %d\n", H[i], G[i]);
			return 0;
		}
		*/
		memset(f, -1, sizeof f);
		f[0][1] = 0;
		for (int i = 0; i < n; ++i) {
			int need = 0;
			for (int k = 0; k * P <= H[i]; ++k, ++need) if ((H[i] - k * P) % Q <= P && ((H[i] - k * P) % Q != 0 || H[i] - k * P == 0)) {
				need = k;
				break;
			}
			int tmp = (H[i] - need * P) / Q;
			for (int can = 0; can <= 1000; ++can) if (f[i][can] != -1) {
				update(f[i+1][can + (H[i] / Q) + (H[i] % Q != 0)], f[i][can]);
				if (H[i] - need * P <= 0) {
					if (can - need >= 0) update(f[i+1][can - need], f[i][can] + G[i]);
					continue;
				}
				if (can + tmp - need - 1 >= 0) update(f[i+1][can + tmp - need - 1], f[i][can] + G[i]);
			}
		}
		int best = -1;
		if (P == Q) {
			best = 0;
			for (int i = 0; i < n; ++i) {
				best += G[i];
			}
		} else 
		for (int can = 0; can <= 1000; ++can) update(best, f[n][can]);
		printf("Case #%d: %d\n", cas, best); 
	}
	
	return 0;
}

// hehe ~


