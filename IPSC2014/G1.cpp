// File Name: G1.cpp
// Author: YangYue
// Created Time: Sun Jun 15 21:46:42 2014
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

int n, m;
char s[1005];
int Pos[1005];
int point[1005];
int f[23][1300005];
bool dp(int k, int mask) {
	if (f[k][mask] != -1) return f[k][mask];
	for (int i = 0; i < m; ++i) {
		if (mask >> i & 1) continue;
		int nextmask = mask;
		if (point[k+1] != -1) nextmask |= (1 << point[k+1]);
		nextmask |= (1 << i);
		if (!dp(k+1, nextmask)) {
			f[k][mask] = 1;
			return 1;
		}
	}
	f[k][mask] = 0;
	return 0;
}
int check() {
	for (int i = 1; i <= m; ++i) {
		int who = i % 2;
		bool done = 0;
		for (int j = m; j >= i; --j) if (s[j] == '1' && who != j % 2) {
			done = 1;
			s[j] = '0';
			break;
		}
		if (!done) {
			bool yes = 0;
			for (int j = m; j >= i; --j) if (s[j] == '1' && who == j % 2) {
				yes = 1;
			}
			if (yes) return who;
			int cnt = 0;
			for (int j = m + 1; j <= n; ++j) if (s[j] == '1') ++cnt;	
			if (cnt % 2 == 1) return who;
			else return 1 - who;
		}
	}
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);	
		scanf("%s", s + 1);
		m = 0;
		memset(point, -1, sizeof point);
		memset(f, -1, sizeof f);
		for (int i = 1; i <= n; ++i) if (s[i] == '1') {
			point[i] = m;
			Pos[m++] = i;
		}
		/*
		if (dp(0, 0)) puts("Adam");
		else puts("Betka");
		*/
		if (check()) puts("Adam");
		else puts("Betka");
	}
	
	return 0;
}

// hehe ~


