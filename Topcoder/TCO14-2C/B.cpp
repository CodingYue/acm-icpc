// File Name: B.cpp
// Author: YangYue
// Created Time: Sun Jul  6 00:21:12 2014
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

class CliqueGraph {
public:
	int n, m, K;
	vector<int> edges[100005];
	int que[5555], vis[5555], d[5555];
	void add(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	long long calcSum(int N, vector <int> V, vector <int> sizes) {
		n = N;
		m = V.size();
		K = sizes.size();
		int p = 1;
		for (int i = 0; i < K; ++i) {
			int t = sizes[i];
			int now = ++n;
			for (int k = p; k < p + t; ++k) {
				add(V[k-1] + 1, now);
			}
			p += t;
		}
		int res = 0;
		for (int i = 1; i <= n - K; ++i) {
			memset(vis, 0, sizeof vis);
			d[i] = 0;
			int front, tail; que[front = tail = 0] = i;
			vis[i] = true;
			for (; front <= tail; ++front) {
				int u = que[front];
				for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) if (!vis[*it]) {
					que[++tail] = *it;
					d[*it] = d[u] + 1;
					vis[*it] = 1;
				}
			}
			for (int j = i + 1; j <= n - K; ++j) res += d[j] / 2;
		}
		return res;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	CliqueGraph *obj;
	long long answer;
	obj = new CliqueGraph();
	clock_t startTime = clock();
	answer = obj->calcSum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	vector <int> p1;
	vector <int> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {0,1,2,0,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 8ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	int t1[] = {0,1,2,3,1,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 12ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 15;
	int t1[] = {1,3,5,7,9,11,13,0,2,3,6,7,10,11,14,0,4,5,6,7,12,13,14,0,8,9,10,11,12,13,14,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {8,8,8,8};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 130ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
// hehe ~


