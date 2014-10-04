// File Name: A.cpp
// Author: YangYue
// Created Time: Sat Sep 20 20:59:15 2014
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

	int n; scanf("%d", &n);

	if (n < 4) {
		puts("NO");
		return 0;
	}

	if (n % 2 == 0) {
		puts("YES");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		puts("24 * 1 = 24");
		for (int x = 5; x <= n; x += 2) {
			printf("%d - %d = 1\n", x+1, x);
			puts("24 * 1 = 24");
		}
	} else {
		puts("YES");
		puts("3 + 4 = 7");
		puts("5 + 7 = 12");
		puts("12 * 2 = 24");
		puts("24 * 1 = 24");
		for (int x = 6; x <= n; x += 2) {
			printf("%d - %d = 1\n", x + 1, x);
			puts("24 * 1 = 24");
		}
	}

	return 0;
}

// hehe ~


