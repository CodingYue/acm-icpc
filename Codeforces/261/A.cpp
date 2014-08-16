// File Name: A.cpp
// Author: YangYue
// Created Time: Fri Aug 15 23:32:22 2014
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

	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	int dx = abs(x1-x2);
	int dy = abs(y1-y2);
	if (dx && dy && dx != dy) {
		puts("-1");
	} else {
		if (dx && dy) {
			printf("%d %d %d %d\n", x1, y2, x2, y1);
		} else
		if (dx == 0) {
			printf("%d %d %d %d\n", x1 + dy, y1, x1 + dy, y2);
		} else 
		if (dy == 0) {
			printf("%d %d %d %d\n", x1, y1 + dx, x2, y1 + dx);
		} else {
			puts("-1");
		}
	}
	
	return 0;
}

// hehe ~


