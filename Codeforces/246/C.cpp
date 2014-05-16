// File Name: C.cpp
// Author: YangYue
// Created Time: Fri May 16 10:18:50 2014
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

int pm;
int prime[MaxN];
int a[MaxN], pos[MaxN];
bool flag[MaxN];
pair<int, int> A[MaxN];
void pre(int n) {
	flag[1] = 1;
	for (int i = 2; i <= n; ++i) if (!flag[i]) {
		prime[pm++] = i;
		for (int j = i + i; j <= n; j += i) flag[j] = 1;
	}
}
vector<pair<int, int> > res;
void SWAP(int i, int j) {
	if (i == j) return;
	if (i > j) swap(i, j);
	res.push_back(MP(i, j));
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
	pos[a[i]] = i;
	pos[a[j]] = j;
}
int main()
{
	//freopen("in","r",stdin);

	int n = 100000;
	pre(n);
	for (int i = 2; i <= n; ++i) {
		if (!flag[i]) continue;
		if (i % 2 == 0) {
			for (int j = 0; j < pm && prime[j] <= i; ++j) if (!flag[i - prime[j]]) {
				A[i] = MP(prime[j], i - prime[j]);
				break;
			}
		}
	}
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (i == pos[i]) continue;
		int tmp = pos[i] - i + 1;
		if (!flag[tmp]) {
			SWAP(i, pos[i]);
			continue;
		}
		++tmp;
		if (tmp % 2 == 0) {
			int k = A[tmp].first + i - 1;
			SWAP(pos[i], k);
			SWAP(k, i);
		} else {
			++tmp;
			int k2 = pos[i] - 1;
			int k1 = i + A[tmp - 2].first - 1;
			SWAP(pos[i], k2);
			SWAP(k1, k2);
			SWAP(i, k1);
		}
	}
	printf("%d\n", (int) res.size());
	for (int i = 0; i < (int) res.size(); ++i) printf("%d %d\n", res[i].first, res[i].second);
	
	return 0;
}

// hehe ~


