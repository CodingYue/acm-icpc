// File Name: 4879.cpp
// Author: YangYue
// Created Time: Wed Jul 30 12:44:38 2014
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
typedef pair<PLL, int> PLLI;

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
const int MOD = (int) 1e9 + 7;
const int dk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int transchar(char x) {
	if (x == 'L') return 3;
	if (x == 'R') return 1;
	if (x == 'U') return 2;
	return 0;
}
LL m;
int n;
int fa[MaxN], size[MaxN];
int rowcnt, colcnt;
int num[MaxN];
LL numcol[MaxN], numrow[MaxN];
PII location[MaxN];
map<LL, int> row_map, col_map;
map<PLL, int> Who;
set<int> rowset[MaxN], colset[MaxN];
pair<PII, int> event[MaxN];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x != y) {
		fa[x] = y;
		size[y] += size[x];
	}
}
int countrow(LL x) {
	if (!row_map.count(x)) {
		row_map[x] = ++rowcnt;
		numrow[rowcnt] = x;
	}
	return row_map[x];
}
int countcol(LL x) {
	if (!col_map.count(x)) {
		col_map[x] = ++colcnt;
		numcol[colcnt] = x;
	}
	return col_map[x];
}
int getWho(LL x, LL y) {
	if (!Who.count(MP(x, y))) return -1;
	return Who[MP(x, y)];
}
LL dist(int a, int b) {
	LL x = (numrow[location[a].first] - numrow[location[b].first]) % MOD;
	LL y = (numcol[location[a].second] - numcol[location[b].second]) % MOD;
	return (x * x + y * y) % MOD;
}
int tot;
int main()
{
	//freopen("in","r",stdin);

	while (scanf("%d %I64d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i) {
			LL x, y; scanf("%I64d %I64d", &x, &y);
			location[i] = MP(countrow(x), countcol(y));
			event[i-1] = MP(location[i], i);
			num[i] = i;
			fa[i] = i;
			size[i] = 1;
		}
		sort(event, event + n);
		for (int i = 0; i < n; ) {
			int j = i;
			for (j = i; j < n && event[i].first == event[j].first; ++j)
				Union(event[j].second, event[i].second);
			LL x = numrow[event[i].first.first];
			LL y = numcol[event[i].first.second];
			Who[MP(x, y)] = event[i].second;
			rowset[event[i].first.first].insert(event[i].second);
			colset[event[i].first.second].insert(event[i].second);
			i = j;
		}
		tot = n;
		int Q; scanf("%d", &Q);
		int lastans = 0;
		while (Q--) {
			char buf[2]; int x;
			scanf("%s %d", buf, &x);
			x ^= lastans;
			if (buf[0] == 'Q') {
				x = num[x];		
				int y = get(x);
				LL res = 0;
				for (set<int> :: iterator it = rowset[location[y].first].begin(); it != rowset[location[y].first].end(); ) {
					set<int> :: iterator tmp = it;
					++it;
					if (*tmp == y) continue;
					res += dist(*tmp, y) * size[*tmp];
					res %= MOD;
					Union(*tmp, y);
					rowset[location[y].first].erase(tmp);
					Who.erase(MP(numrow[location[*tmp].first], numcol[location[*tmp].second]));
				}
				for (set<int> :: iterator it = colset[location[y].second].begin(); it != colset[location[y].second].end(); ) {
					set<int> :: iterator tmp = it;
					++it;
					if (*tmp == y) continue;
					res += dist(*tmp, y) * size[*tmp];
					res %= MOD;
					Union(*tmp, y);
					colset[location[y].second].erase(tmp);
					Who.erase(MP(numrow[location[*tmp].first], numcol[location[*tmp].second]));
				}
				printf("%d\n", (int) res);
				lastans = res;
			} else {
				LL d; scanf("%I64d", &d);
				int y = get(num[x]);
				LL curx = numrow[location[y].first];
				LL cury = numcol[location[y].second];
				--size[y];

				num[x] = ++tot;
				y = num[x];
				fa[y] = y;
				size[y] = 1;
				int k = transchar(buf[0]);
				
				curx += d * dk[k][0];
				cury += d * dk[k][1];
				int who = getWho(curx, cury);
				if (who == -1) {
					int nx = countrow(curx);
					int ny = countcol(cury);
					location[y] = MP(nx, ny);
					rowset[nx].insert(y);
					colset[ny].insert(y);
					Who[MP(curx, cury)] = y;
				} else {
					Union(y, who);
				}
			}
		}
	}
	
	return 0;
}

// hehe ~


