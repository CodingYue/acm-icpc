// File Name: A.cpp
// Author: YangYue
// Created Time: Sun Oct  5 21:50:21 2014
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

PII get(int x) {
	if (x <= 4) {
		return MP(x, 1);
	}
	if ((x-4) % 3 == 0) {
		return MP(4, (x-1)/3*2-1);
	}
	return MP((x-4) % 3, (x-1)/3*2+1);
}

int main()
{
	//freopen("in","r",stdin);

	int n; scanf("%d", &n);
	string s[6];
	s[0] = "+------------------------+";
	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	s[3] = "|#.......................|";
	s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	s[5] = "+------------------------+";
	for (int x = 0; x < n; ++x) {
		PII coor = get(x+1);
		s[coor.first][coor.second] = 'O';
	}
	for (int i = 0; i < 6; ++i) cout << s[i] << endl;
	
	return 0;
}

// hehe ~


