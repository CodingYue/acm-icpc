// File Name: 1B.cpp
// Author: YangYue
// Created Time: Sun Apr 20 15:50:27 2014
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

int L;
set<string> SET;
bool solve(string a, string b) {
	stringstream s << a;
	int number;
	char c;
	vector<char> v;
	while (s >> number >> c) {
		for (int i = 0; i < number; ++i) v.push_back(c);
	}
	int n = v.size() / L;
	for (int i = 0; i < v.size(); ++i) {
		mat[i % n][i / n] = 
	}
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);

	while (cases--) {
	}
	
	return 0;
}

// hehe ~


