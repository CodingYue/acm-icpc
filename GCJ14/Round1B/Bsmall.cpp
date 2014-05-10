// File Name: Bsmall.cpp
// Author: YangYue
// Created Time: Sun May  4 00:28:07 2014
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

int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		int A, B, K;
		scanf("%d %d %d", &A, &B, &K);
		int cnt = 0;
		for (int i = 0; i < A; ++i)
		for (int j = 0; j < B; ++j) if ((i & j) < K) {
			++cnt;
		}
		printf("%d\n", cnt);
	}

	return 0;
}

// hehe ~


