// File Name: A.cpp
// Author: YangYue
// Created Time: Sat Apr 12 17:50:21 2014
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
typedef unsigned int uint;

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

int pm;
uint C[MaxN];
uint sumd[MaxN];
uint prime[MaxN], miu[MaxN];
uint ans[MaxN];
PII seq[MaxN];
bool flag[MaxN];
struct Query{
	int n, m, a, idx;
	bool operator < (const Query &b) const {
		return a < b.a;
	}
	void init(int __idx) {
		scanf("%d %d %d", &n, &m, &a);
		if (n > m) swap(n, m);
		idx = __idx;
	}
} query[MaxN];
void add(int x, int v) {
	for (; x <= 100000; x += lowbit(x))
		C[x] += v;
}
uint sum(int x) {
	LL res = 0;
	for (; x; x -= lowbit(x)) res += C[x];
	return res;
}
void pre(int n) {
	miu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!flag[i]) {
			prime[pm++] = i;
			miu[i] = -1;
		}
		for (int j = 0; j < pm && (LL) prime[j] * i <= n; ++j) {
			flag[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				miu[i * prime[j]] = 0;
				break;
			}
			miu[i * prime[j]] = miu[i] * -1;
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i) sumd[j] += i;
	for (int i = 1; i <= n; ++i) seq[i - 1] = PII(sumd[i], i);
	sort(seq + 1, seq + n);
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);

	pre(100000);
	int Q; scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		query[i].init(i);
	}
	sort(query, query + Q);
	int cur = 0;
	for (int i = 0; i < Q; ++i) {
		if (query[i].a <= 0) {
			ans[query[i].idx] = 0;
			continue;
		}
		int bound = upper_bound(seq, seq + 100000, PII(query[i].a, INF)) - seq;
		while (cur < bound) {
			int now = seq[cur].second;
			for (int x = now; x <= 100000; x += now) {
				add(x, miu[x / now] * sumd[now]);
			}
			++cur;
		}
		LL n = query[i].n, m = query[i].m;
		for (int d = 1; d <= n; ++d) {
			int next = min(n / (n / d), m / (m / d));
			ans[query[i].idx] += (sum(next) - sum(d - 1)) * (n / d) * (m / d);
			d = next;
		}
	}
	for (int i = 0; i < Q; ++i) printf("%u\n", ans[i] % (1u << 31));
	
	return 0;
}

// hehe ~


