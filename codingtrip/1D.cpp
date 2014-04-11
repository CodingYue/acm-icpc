// File Name: 1D.cpp
// Author: YangYue
// Created Time: Thu Apr 10 19:11:32 2014
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

typedef unsigned long long LL;
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

	int cases; cin >> cases;
	while (cases--) {
		int n;
		LL M;
		cin >> M >> n;
		int len = 0;
		/*
		for (LL x = M; x; x >>= 1) ++len;
		if (len > n) while(1);
		*/
		M &= (1ll << n) - 1;
		LL t = M;
		vector<LL> v;
		for (int i = 0; i < n; ++i) {
			t = (t >> 1) | ((t & 1) << (n - 1));
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			cout << (v[i] & 1);
		}
		puts("");
	}
	
	return 0;
}

// hehe ~


