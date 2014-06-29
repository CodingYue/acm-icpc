// File Name: 10900.cpp
// Author: YangYue
// Created Time: Sun Jun 29 17:58:55 2014
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

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

int n;
double f[55];
double g2(double c, double a, double b) {
	return c / 2 * (b*b - a*a);
}
double g(double c, double a, double b) {
	return c * (b - a);
}
int main()
{
	//freopen("in","r",stdin);

	double t = 0;
	while (scanf("%d %lf", &n, &t), n) {
		if (t == 1.0) {
			printf("%d.000\n", 1<<n);
		}
		f[n] = 1<<n;
		for (int i = n - 1; i >= 0; --i) {
			double xp = (1<<i) / f[i+1];
			if (dcmp(xp - t) >= 0) {
				f[i] = g2(f[i+1], xp, 1.) + g(1<<i, t, xp);
			} else {
				f[i] = g2(f[i+1], t, 1);
			}
			f[i] /= (1 - t);
		}
		printf("%.3f\n", f[0]);
	}
	
	return 0;
}

// hehe ~


