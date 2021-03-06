// File Name: C.cpp
// Author: YangYue
// Created Time: Sun Jul  6 00:37:11 2014
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

#define NO "impossible"
#define YES "possible"
int l[MaxN],r[MaxN],ans[MaxN];
bool cmp(int x, int y) {
	return ans[x] < ans[y];
}
int n,m,p[MaxN];
PII mytmp[MaxN];
int tmp[MaxN];
PII E[MaxN];
int vol[MaxN];
int Vn;
int S, T;
int h[MaxN], vh[MaxN];
struct Edge {
    int v, f; Edge *next, *pre;
    Edge(int v, int f, Edge *next)
        : v(v), f(f), next(next) {}
} *g[MaxN];
void add(int u, int v, int f) {
    g[u] = new Edge(v, f, g[u]);
    g[v] = new Edge(u, 0, g[v]);
    g[u]->pre = g[v]; g[v]->pre = g[u];
}
int sap(int u, int flow) {
    if (u == T) return flow;
    int tmp = Vn - 1, f = 0;
    for (Edge *p = g[u]; p; p = p->next) {
        if (p->f && h[u] == h[p->v] + 1) {
            int tmpf = sap(p->v, min(flow - f, p->f));
            p->f -= tmpf, p->pre->f += tmpf, f += tmpf;
            if (h[S] == Vn || f == flow) return f;
        }
        if (p->f) tmp = min(tmp, h[p->v]);
    }
    if (!f) {
        --vh[h[u]];
        if (!vh[h[u]]) h[S] = Vn;
        else vh[h[u] = tmp + 1]++;
    }
    return f;
}
class InverseRMQ {
public:
	string possible(int _n, vector <int> A, vector <int> B, vector <int> ANS) {
		n = _n;
		m = A.size();
		int tmpn = 0;
		for (int i = 1; i <= m; ++i) {
			l[i] = A[i - 1], r[i] = B[i - 1], ans[i] = ANS[i - 1]; p[i] = i;
			tmp[++tmpn] = l[i]; tmp[++tmpn] = r[i];
		}
		sort(tmp + 1, tmp + tmpn + 1);
		tmpn = unique(tmp + 1, tmp + tmpn + 1) - tmp - 1;
		int Tot = 0;
		for (int i = 1; i <= tmpn; ++i) {
			if (tmp[i] > tmp[i - 1] + 1) {
				mytmp[++Tot] = MP(tmp[i - 1] + 1, tmp[i] - 1);
			};
			mytmp[++Tot] = MP(tmp[i], tmp[i]);
		}
		if (tmp[tmpn] < n) mytmp[++Tot] = MP(tmp[tmpn] + 1, n);
		sort(p + 1, p + m + 1, cmp);
		int now1 = 0, now2 = Tot;
		int nEdge = 0;
		ans[0] = 0;
		for (int I = 1; I <= m; ++I) {
			int i = p[I];
			if (ans[i] > ans[i - 1] + 1) {
				++now1; vol[now1] = ans[i] - ans[i - 1] - 1;
				for (int j = 1; j <= Tot; ++j) {
					int x = mytmp[j].first;
					bool valid = true;
					for (int k = 1; k <= m; ++k) if (ans[k] < ans[i]) 
						valid &= (!(l[k] <= x && x <= r[k]));
					if (valid) E[++nEdge] = MP(now1, j);
				}
			}
			++now1; vol[now1] = 1;
			for (int j = 1; j <= Tot; ++j) {
				int x = mytmp[j].first;
				bool valid = true;
				for (int k = 1; k <= m; ++k) if (ans[k] < ans[i]) 
					valid &= (!(l[k] <= x && x <= r[k]));
				else if (ans[k] == ans[i]) valid &= (l[k] <= x && x <= r[k]);
				if (valid) E[++nEdge] = MP(now1, j);
			}
		}
		if (ans[p[m]] < n) {
			++now1; vol[now1] = n - ans[p[m]];
			for (int j = 1; j <= Tot; ++j) {
				int x = mytmp[j].first;
				bool valid = true;
				for (int k = 1; k <= m; ++k) valid &= (!(l[k] <= x && x <= r[k]));
				if (valid) E[++nEdge] = MP(now1, j);
			}
		}
		S = now1 + now2 + 1, T = S + 1;
		for (int i = 1; i <= now1; ++i) add(S,i,vol[i]);
		for (int i = 1; i <= now2; ++i) {
			add(now1 + i, T, mytmp[i].second - mytmp[i].first + 1);
		}
		Vn = now1 + now2 + 2;
		for (int i = 1; i <= nEdge; ++i) {
			add(E[i].first, now1 + E[i].second, INF);
		}
		h[0] = Vn;
		int res = 0;
		while (h[S] < Vn) res += sap(S, INF);
		if (res == n) return "Possible";
		else return "Impossible";
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, string p4) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	InverseRMQ *obj;
	string answer;
	obj = new InverseRMQ();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p3;
	string p4;
	
	{
	// ----- test 0 -----
	p0 = 5;
	int t1[] = {1,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,4,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,4,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,3,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 600;
	int t1[] = {1,101,201,301,401,501};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100,200,300,400,500,600};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {100,200,300,400,500,600};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000000000;
	int t1[] = {1234,1234};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5678,5678};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10000,20000};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 8;
	int t1[] = {1,2,3,4,5,6,7,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,4,5,6,7,8};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {4,8,2,5,6,3,7,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1000000000;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1000000000};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {19911120};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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


