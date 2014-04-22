// File Name: A.cpp
// Author: YangYue
// Created Time: Tue Apr 22 20:18:08 2014
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

const char cont[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main()
{
	//freopen("in","r",stdin);

	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i)
		if (s[i] != s[n - i - 1]) {
			puts("NO");
			return 0;
		}
	for (int i = 0; i < n; ++i) {
		bool find = 0;
		for (int j = 0; j < 11; ++j) if (cont[j] == s[i]) {
			find = 1;
		}
		if (!find) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	
	return 0;
}

// hehe ~


