// File Name: B.cpp
// Author: YangYue
// Created Time: Sat May 24 16:39:22 2014
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
typedef pair<int,int> Pxx;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLx;

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
const double DxNF = 1e100;
const int xNF = 1000000006;
const LL LxNF = 1000000000000000005ll;

int n, m, Q, A[1233][1233];
int L[1233], R[1233];
set<int> row[1233], col[1233];

int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d %d", &n, &m, &Q);
	for (int i = 1; i <= n; ++i) {
		row[i].insert(0);
		row[i].insert(m + 1);
	}
	for (int i = 1; i <= m; ++i) {
		col[i].insert(0);
		col[i].insert(n + 1);
	}
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) {
		scanf("%d", &A[i][j]);
		if (!A[i][j]) {
			row[i].insert(j);
			col[j].insert(i);
		}
	}
	while (Q--) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if (op == 2) {
			if (row[x].find(y) != row[x].end()) {
				puts("0");
				continue;
			}
			set<int> :: iterator it;
			L[0] = R[0] = L[n + 1] = R[n + 1] = -1;
			for (int k = 1; k <= n; ++k) {
				it = row[k].lower_bound(y);
				if ((*it) == y) {
					L[k] = R[k] = 0;
				} else {
					R[k] = (*it) - y;
					--it;
					L[k] = y - (*it);
				}
			}
			int ans = 0;
			int u = x, d = x;
			int best = L[x];
			ans = max(ans,best);
			for (int len = 2; len <= n; ++len) {
				if (L[u - 1] > L[d + 1] && u > 1) {
					--u;
					best = min(best,L[u]);
				} else {
					++d;
					best = min(best,L[d]);
				}
				ans = max(ans,len * best);
			}
			u = x, d = x;
			best = R[x];
			ans = max(ans,best);
			for (int len = 2; len <= n; ++len) {
				if (R[u - 1] > R[d + 1] && u > 1) {
					--u;
					best = min(best,R[u]);
				} else {
					++d;
					best = min(best,R[d]);
				}
				ans = max(ans,len * best);
			}
			L[0] = R[0] = L[m + 1] = R[m + 1] = -1;
			for (int k = 1; k <= m; ++k) {
				it = col[k].lower_bound(x);
				if ((*it) == x) {
					L[k] = R[k] = 0;
				} else {
					R[k] = (*it) - x;
					--it;
					L[k] = x - (*it);
				}
			}
			u = y, d = y;
			best = L[y];
			ans = max(ans,best);
			for (int len = 2; len <= m; ++len) {
				if (L[u - 1] > L[d + 1] && u > 1) {
					--u;
					best = min(best,L[u]);
				} else {
					++d;
					best = min(best,L[d]);
				}
				ans = max(ans,len * best);
			}
			u = y, d = y;
			best = R[y];
			ans = max(ans,best);
			for (int len = 2; len <= m; ++len) {
				if (R[u - 1] > R[d + 1] && u > 1) {
					--u;
					best = min(best,R[u]);
				} else {
					++d;
					best = min(best,R[d]);
				}
				ans = max(ans,len * best);
			}
			printf("%d\n",ans);
		}
		
		if (op == 1) {
			if (row[x].find(y) != row[x].end()) {
				row[x].erase(row[x].find(y));
				col[y].erase(col[y].find(x));
			} else {
				row[x].insert(y);
				col[y].insert(x);
			}
		}
	}
	
	return 0;
}

// hehe ~

