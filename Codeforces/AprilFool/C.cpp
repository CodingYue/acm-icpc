// File Name: C.cpp
// Author: YangYue
// Created Time: Tue Apr  1 23:45:16 2014
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

int main()
{
	//freopen("in","r",stdin);

	int a[5];
	for (int i = 0; i < 5; ++i) scanf("%d", a + i);
	int Min = INF;
	Min = min(Min, a[0]);
	Min = min(Min, a[1]);
	Min = min(Min, a[2] / 2);
	Min = min(Min, a[3] / 7);
	Min = min(Min, a[4] / 4);
	printf("%d\n", Min);
	
	return 0;
}

// hehe ~


