// File Name: 1A.cpp
// Author: YangYue
// Created Time: Sun Apr 20 14:42:47 2014
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
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		LL n; cin >> n;
		printf("Case %d: ", ++cas);
		if (n <= 2) puts("no solution");
		else {
			cout << 2 * n - 2 << ' ' << n - 1 << ' ' << 1 << endl;
		}
	}
	
	return 0;
}

// hehe ~


