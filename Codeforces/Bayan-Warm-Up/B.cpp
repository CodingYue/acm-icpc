// File Name: B.cpp
// Author: YangYue
// Created Time: Sun Oct  5 22:08:23 2014
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

char dirx[22];
char diry[22];
int n, m;
int num(int x, int y) {
	return x * m + y;
}
bool can[444][444];
void add(int x, int y, int tx, int ty) {
	if (tx < 0 || ty < 0 || tx >= n || ty >= m) return;
	can[num(x,y)][num(tx,ty)] = 1;
}
int main()
{
	//freopen("in","r",stdin);
	
	scanf("%d %d", &n, &m);
	scanf("%s %s", dirx, diry);

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (dirx[x] == '<') {
				add(x, y, x, y-1);
			} else add(x, y, x, y+1);
			if (diry[y] == 'v') {
				add(x, y, x+1, y);
			} else add(x, y, x-1, y);
			can[num(x,y)][num(x,y)] = 1;
		}
	}


	int tot = n * m;
	for (int k = 0; k < tot; ++k)
		for (int i = 0; i < tot; ++i)
			for (int j = 0; j < tot; ++j) can[i][j] |= (can[i][k] & can[k][j]);
	for (int x = 0; x < tot; ++x)
		for (int y = 0; y < tot; ++y) if (!can[x][y]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	
	return 0;
}

// hehe ~


