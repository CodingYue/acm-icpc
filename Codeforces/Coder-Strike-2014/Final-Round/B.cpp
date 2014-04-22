// File Name: B.cpp
// Author: YangYue
// Created Time: Tue Apr 22 21:20:58 2014
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
int op[MaxN];
int man[MaxN];
int state[MaxN];
bool vis[MaxN];

int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		char o[20] = {0};
		int mm = 0;
		scanf("%s %d", o, &mm);
		op[i] = o[0];
		man[i] = mm;

		if (!vis[mm]) {
			if (op[i] == '+') state[mm] = 2;
			else state[mm] = 1;
			vis[mm] = 1;		
		}
	}
	set<int> h;
	set<int> ppp;
	set<int> cant;
	for (int i = 1; i <= n; ++i) {
		if (state[i] == 1) h.insert(i);
		else if (state[i] == 2) ppp.insert(i);
	}
	if (h.size() != 0) {
		for (set<int> :: iterator it = ppp.begin(); it != ppp.end(); ++it) {
			int x = *it;
			cant.insert(x);
		}
		ppp.clear();
	}
	int max = h.size();
	for (int i = 0; i < m; ++i) {
		if (op[i] == '-') {
			h.erase(man[i]);
			if (h.size()) cant.insert(man[i]);
			else if (!cant.count(man[i])) {
				ppp.insert(man[i]);
			}
		} else
		if (op[i] == '+') {
			if (!h.size() && i && op[i-1] == '-' && man[i-1] == man[i]) {
				h.insert(man[i]);
				ppp.erase(man[i]);
				continue;
			}
			if (h.size() || max) cant.insert(man[i]);
			if (ppp.size()) {
				for (set<int> :: iterator it = ppp.begin(); it != ppp.end(); ++it) {
					int x = *it;
					if (x != man[i]) cant.insert(x);
				}
				ppp.clear();
			}
			h.insert(man[i]);
		}
	}
	vector<int> res;
	for (int i = 1; i <= n; ++i) if (!cant.count(i)) res.push_back(i);
	printf("%d\n", (int) res.size());
	for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);
	puts("");
	
	return 0;
}

// hehe ~


