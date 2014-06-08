// File Name: C.cpp
// Author: YangYue
// Created Time: Sat May 24 15:25:55 2014
//headers 
#include <queue>
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

const int MOD = (int) 1e9 + 7;

int tot;
struct Node
{
	int value, idx;
	Node *ch[20], *fail;
} arr[MaxN], *root;
Node *newNode()
{
	Node *x = &arr[tot];
	x->value = 0;
	x->idx = tot++;
	x->fail = NULL;
	memset(x->ch, 0, sizeof x->ch);
	return x;
}
void insert(int *s, int len, int value)
{
	Node *now = root;
	for (int i = len - 1; i >= 0; --i)
	{
		int k = s[i];
		if (now->ch[k] == NULL) now->ch[k] = newNode();
		now = now->ch[k];
	}
	now->value += value;
}
queue < Node* > que;
void build_fail()
{
	que.push(root); root->fail = root;
	while (!que.empty())
	{
		Node *now = que.front(); que.pop();
		now->value += now->fail->value;
		for (int i = 0; i < 20; ++i) if (now->ch[i] == NULL) {
			if (now == root) now->ch[i] = root; else
				now->ch[i] = now->fail->ch[i];
		} else {
			if (now == root) now->ch[i]->fail = root; else
				now->ch[i]->fail = now->fail->ch[i];
			que.push(now->ch[i]);
		}
	}
}
int n, m, K;
int l[205], r[205], lenl, lenr;
int s[205], lens;
int f[205][205][505][2][2];
int dp(int i, int idx, int value, bool fbool, bool first) {
	if (i < 0) return 1;
	if (f[i][idx][value][fbool][first] != -1) {
		return f[i][idx][value][fbool][first];
	}
	LL res = 0;
	res = 0;
	for (int num = (first ? 1 : 0); num <= (fbool ? m - 1 : s[i]); ++num) {
		int nextidx = arr[idx].ch[num]->idx;
		int nextvalue = arr[nextidx].value + value;
		if (nextvalue <= K) 
			res += dp(i - 1, nextidx, nextvalue, fbool | (num < s[i]), 0);
	}
	f[i][idx][value][fbool][first] = res % MOD;
	return res % MOD;
}
int calc(int *r, int len) {
	for (int i = 0; i < len; ++i) {
		s[i] = r[i];
	}
	memset(f, -1, sizeof f);
	LL res = dp(len - 1, 0, 0, 0, 1);
	
	for (int i = len - 2; i >= 0; --i) {
		res += dp(i, 0, 0, 1, 1);
	}
	
	return res % MOD;
}
void read(int *r, int &len) {
	scanf("%d", &len);
	for (int i = 0; i < len; ++i) {
		scanf("%d", r + i);
	}
	reverse(r, r + len);
}
bool check(int *s, int len) {
	Node *now = root;
	int value = 0;
	for (int i = len - 1; i >= 0; --i) {
		now = now->ch[s[i]];
		value += now->value;
		if (value > K) return false;
	}
	return true;
}
int main()
{
	//freopen("in","r",stdin);

	scanf("%d %d %d", &n, &m, &K);
	read(l, lenl);
	read(r, lenr);
	root = newNode();
	for (int i = 0; i < n; ++i) {
		read(s, lens);
		int value; scanf("%d", &value);
		insert(s, lens, value);
	}
	build_fail();
	printf("%d\n", (calc(r, lenr) - calc(l, lenl) + check(l, lenl) + MOD) % MOD);
	
	return 0;
}

// hehe ~


