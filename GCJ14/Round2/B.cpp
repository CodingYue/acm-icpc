// File Name: B.cpp
// Author: YangYue
// Created Time: Sat May 31 22:30:22 2014
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

const int MaxN = 1005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int a[MaxN], b[MaxN];
map<int, int> Hash;

int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		scanf("%d", &n);
		int pos = -1;
		int Max = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (a[i] > Max) {
				pos = i;
				Max = a[i];
			}
		}
		int res = INF;
		for (int i = 0; i < n; ++i) {
			int tmp = abs(pos - i);
			int sum = 0;
			memcpy(b, a, sizeof a);
			if (i < pos) {
				for (int k = pos; k > i; --k) swap(b[k], b[k-1]);
				for (int k = 0; k < n; ++k) Hash[b[k]] = k;
				sort(b, b + i);
				sort(b + i + 1, b + n);
				reverse(b + i + 1, b + n);
			} else {
				for (int k = pos; k < i; ++k) swap(b[k], b[k+1]);
				for (int k = 0; k < n; ++k) Hash[b[k]] = k;
				sort(b + i + 1, b + n); 
				sort(b, b + i);
				reverse(b + i + 1, b + n);
			}
			for (int k = 0; k < n; ++k) sum += abs(Hash[b[k]] - k);
			if (res > tmp + sum / 2) {
				res = tmp + sum / 2;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}

// hehe ~


