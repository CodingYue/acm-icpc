// File Name: A.cpp
// Author: YangYue
// Created Time: Sun May  4 00:12:21 2014
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

vector<pair<char, int> > v[105];

int check(int n) {
	for (int i = 0; i < n; ++i) if (v[i].size() != v[0].size()) {
		return -1;
	}
	for (int i = 1; i < n; ++i)
	for (int j = 0; j < v[0].size(); ++j) {
		if (v[0][j].first != v[i][j].first) return -1;
	}
	int res = 0;
	for (int k = 0; k < v[0].size(); ++k) {
		int best = 10000;
		for (int x = 1; x <= 100; ++x) {
			int cnt = 0;
			for (int i = 0; i < n; ++i) cnt += abs(x - v[i][k].second);
			best = min(best, cnt);
		}
		res += best;
	}
	return res;
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;

	while (cases--) {
		printf("Case #%d: ", ++cas);
		int n = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			v[i].clear();
			string s; cin >> s;	
			for (int k = 0; k < s.size(); ) {
				int j = k;
				for (; j < s.size() && s[k] == s[j]; ++j);
				v[i].push_back(MP(s[k], j - k));
				k = j;
			}
		}
		int res = check(n);
		if (res == -1) {
			puts("Fegla Won");
		} else {
			printf("%d\n", res);
		}
	}

	
	return 0;
}

// hehe ~


