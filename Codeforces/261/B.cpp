// File Name: B.cpp
// Author: YangYue
// Created Time: Fri Aug 15 23:39:24 2014
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

int a[MaxN];
map<int, int> cnt;

int main()
{
	//freopen("in","r",stdin);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		cnt[a[i]]++;
	}

	sort(a, a + n);
	printf("%d ", a[n-1] - a[0]);
	if (a[0] == a[n-1]) {
		LL res = (LL) n * (n-1) / 2;
		cout << res << endl;
	} else {
		LL res = (LL) cnt[a[0]] * cnt[a[n-1]];
		cout << res << endl;
	}
	
	return 0;
}

// hehe ~


