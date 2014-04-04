// File Name: A.cpp
// Author: YangYue
// Created Time: Tue Apr  1 23:33:49 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
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


int c[33], d[33];

int main()
{
	//freopen("in","r",stdin);

	string a, b;
	cin >> a;
	cin >> b;
	for (int i = 0; i < a.size(); i += 2) {
		if (a[i] == '8') c[i / 2] = 0;
		if (a[i] == '(') c[i / 2] = 1;
		if (a[i] == '[') c[i / 2] = 2;
	}
	for (int i = 0; i < b.size(); i += 2) {
		if (b[i] == '8') d[i / 2] = 0;
		if (b[i] == '(') d[i / 2] = 1;
		if (b[i] == '[') d[i / 2] = 2;
	}
	int cnt = 0;
	for (int i = 0; i < a.size() / 2; ++i) {
		if (c[i] == d[i]) continue;
		if ((c[i] + 1) % 3 == d[i]) --cnt;
		else ++cnt;
	}
	if (cnt > 0) puts("TEAM 1 WINS");
	else if (cnt < 0) puts("TEAM 2 WINS");
	else puts("TIE");
	
	return 0;
}

// hehe ~


