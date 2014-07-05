// File Name: I.cpp
// Author: YangYue
// Created Time: Fri Jul  4 23:30:21 2014
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

int tot = 0;
struct Trie {
	int minlen;
	Trie *ch[26];
} arr[MaxN + 1000], *root;
Trie *newTrie() {
	Trie *p = &arr[tot++];
	memset(p->ch, 0, sizeof p->ch);
	p->minlen = INF;
	return p;
}
char s[MaxN];
int insert(int len) {
	Trie *now = root;
	int cur = 0;
	int res = len;
	for (int i = 0; i < len; ++i) {
		int k = s[i] - 'a';
		if (now->ch[k]) {
			now = now->ch[k];
			int tmp = now->minlen - 2 * (cur + 1) + len;
			if (tmp < res) res = tmp;
		} else {
			now->ch[k] = newTrie();
			now = now->ch[k];
		}
		now->minlen = min(now->minlen, len);
		++cur;
	}
	return res;
}
int main()
{
	//freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	while (cases--) {
		tot = 0;
		root = newTrie();
		int n; scanf("%d", &n);
		gets(s);
		int len = strlen(s);
		bool find = 0;
		for (int i = 0; i < len; ++i) if (s[i] == ' ') find = 1;
		if (!find && len > 0) insert(strlen(s));
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			printf("%d\n", insert(strlen(s)) + 1);
		}
	}
	
	return 0;
}

// hehe ~


