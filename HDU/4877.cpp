// File Name: 4877.cpp
// Author: YangYue
// Created Time: Wed Aug 20 22:53:38 2014
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

int upL, upR, upMax;
int dnL, dnR, dnMax;

void update(const set<PII> &SET, const &PII p, int &L, int &R, int &Max) {
	set<PII> :: iterator pos = SET.lower_bound(p);
	int x = p.first;
	int tL = L;
	int tR = R;
	int tMax = Max;
	if (p.second == Max) {
		L = min(L, p.first);
		R = max(R, p.first);
		SET.insert(p);
		return;
	} else if (p.second > Max) {
		Max = p.second;
		L = p.first;
		R = p.first;
	}
	if (tL <= x && x <= tR) {
	}
	if (SET.size()) {
		int
	}
}
int main()
{
	freopen("in","r",stdin);

	int n;
	while (scanf("%d", &n) != EOF) {

		set<PII> up, dn;
		set<PII> contains;
		upMax = dnMax = -INF;
		int lastans = 0;
		for (int i = 0; i < n; ++i) {
			PII p; scanf("%d %d", &p.first, &p.second);
			if (set.count(p)) {
				printf("%d\n", lastans);
				continue;
			}
			contains.insert(p);

			maintain(up, p, upL, upR, upMax);
			maintain(dn, MP(p.first, -p.second), dnL, dnR, dnMax);
		}

	}
	
	return 0;
}

// hehe ~


