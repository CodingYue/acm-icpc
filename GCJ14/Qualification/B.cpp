// File Name: B.cpp
// Author: YangYue
// Created Time: Sat Apr 12 22:15:50 2014
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

double f[MaxN];

int main()
{
	freopen("in","r",stdin);
	
	int cases; scanf("%d", &cases);

	for (int Tk = 1; Tk <= cases; ++Tk) {
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		double now = 2.0;
		double sum = 0;
		double best = X / now;
		for (int i = 1; i <= 100000; ++i) {
			sum += C / now;
			now += F;
			best = min(best, sum + X / now);
		}
		printf("Case #%d: %.8f\n", Tk, best);
	}
	
	return 0;
}

// hehe ~


