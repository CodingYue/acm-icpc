// File Name: A.cpp
// Author: YangYue
// Created Time: Tue Apr 15 12:30:32 2014
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

	string s;
	cin >> s;
	bool can[4] = {0};
	if (s.size() >= 5) can[0] = 1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') can[1] = 1;
		if (s[i] >= 'a' && s[i] <= 'z') can[2] = 1;
		if (s[i] >= '0' && s[i] <= '9') can[3] = 1;
	}
	bool yes = 1;
	for (int i = 0; i < 4; ++i) if (!can[i]) yes = 0;
	if (yes) puts("Correct");
	else puts("Too weak");
	
	return 0;
}

// hehe ~


