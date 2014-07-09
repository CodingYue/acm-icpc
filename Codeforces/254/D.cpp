// File Name: D.cpp
// Author: YangYue
// Created Time: Sun Jul  6 22:45:24 2014
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


int n, tot;
string s;
vector<int> pos[MaxN];
map<string, int> Hash;
map<PII, int> ans;

int main()
{
	//freopen("in","r",stdin);

	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		for (int len = 1; len <= 4 && i + len <= n; ++len) {
			string tmp = s.substr(i, len);
			if (!Hash.count(tmp)) Hash[tmp] = tot++;
			pos[Hash[tmp]].push_back(i);
		}
	}

	int q; scanf("%d" ,&q);
	for (int i = 0; i < q; ++i) {
		string sa, sb;
		cin >> sa >> sb;
		if (!Hash.count(sa) || !Hash.count(sb)) {
			puts("-1");
			continue;
		}
		int a = Hash[sa], b = Hash[sb];
		if (pos[a].size() > pos[b].size()) {
			swap(a, b);
			swap(sa, sb);
		}
		if (ans.count(MP(a,b))) {
			printf("%d\n", ans[MP(a,b)]);
			continue;
		}
		int tmp = INF;
		for (int i = 0; i < pos[a].size(); ++i) {
			int y = upper_bound(pos[b].begin(), pos[b].end(), pos[a][i]) - pos[b].begin();
			int x = y - 1;
			if (x >= 0) {
				int x1 = pos[a][i];
				int y1 = pos[b][x];
				int tt = max(x1 + sa.size(), y1 + sb.size()) - min(x1, y1);
				tmp = min(tt, tmp);
			}
			if (y < pos[b].size()) {
				int x1 = pos[a][i];
				int y1 = pos[b][y];
				int tt = max(x1 + sa.size(), y1 + sb.size()) - min(x1, y1);
				tmp = min(tmp, tt);
			}
		}
		ans[MP(a, b)] = tmp;
		printf("%d\n", tmp);
	}
	
	return 0;
}

// hehe ~


