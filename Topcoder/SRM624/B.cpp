// File Name: B.cpp
// Author: YangYue
// Created Time: Thu Jun 12 23:23:02 2014
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

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const int mod = (int) 1e9 + 9;
class DrivingPlans {
public:
	int m, n, et;
	int ind[4444];
	vector<int> edges[4444];
	struct Edge {
		int v, w;
		Edge *next;
		Edge(){}
		Edge(int v, int w, Edge *next)
			: v(v), w(w), next(next) {
			}
	} *g[4444], ee[44444];
	void ins(int u, int v, int w) {
		ee[et] = Edge(v, w, g[u]);
		g[u] = &ee[et++];
	}
	int que[444444];
	bool inque[444444];
	int dist[2][4444];
	int f[4444];
	void SPFA(int source, int *dist) {
		for (int i = 1; i <= n; ++i) dist[i] = INF;
		dist[source] = 0;
		int front, tail;
		memset(inque, 0, sizeof inque); inque[source] = 1;
		que[front = tail = 0] = source;
		for (; front <= tail; ++front) {
			int u = que[front];
			for (Edge *p = g[u]; p; p = p->next) if (dist[p->v] > dist[u] + p->w) {
				dist[p->v] = dist[u] + p->w;
				if (!inque[p->v]) {
					inque[p->v] = 1;
					que[++tail] = p->v;
				}
			}
			inque[u] = 0;
		}
	}
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
		n = N;
		m = A.size();
		for (int i = 0; i < m; ++i) {
			ins(A[i], B[i], C[i]);
			ins(B[i], A[i], C[i]);
		}
		SPFA(1, dist[0]);
		SPFA(n, dist[1]);
		for (int i = 0; i < m; ++i) {
			if (dist[0][A[i]] + C[i] == dist[0][B[i]]) {
				edges[A[i]].push_back(B[i]);
				ind[B[i]]++;
				printf("%d %d\n", A[i], B[i]);
			}
			if (dist[0][B[i]] + C[i] == dist[0][A[i]]) {
				edges[B[i]].push_back(A[i]);
				ind[A[i]]++;

			}
		}
		int front = 1, tail = 0;
		f[1] = 1;
		for (int i = 1; i <= n; ++i) if (!ind[i]) que[++tail] = i;
		for (; front <= tail; ++front) {
			int u = que[front];
			for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
				int v = *it;
				--ind[v];
				f[v] = (f[v] + f[u]) % mod;
				if (!ind[v]) {
					que[++tail] = v;
				}
			}
		}
		if (ind[n]) return -1;
		return f[n];
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
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
	DrivingPlans *obj;
	int answer;
	obj = new DrivingPlans();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {1,1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	int t1[] = {1,1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 7;
	int t1[] = {1,1,2,3,4,4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4,5,6,7,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,2,2,3,3,4,4};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
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
