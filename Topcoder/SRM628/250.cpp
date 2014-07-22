// File Name: 250.cpp
// Author: YangYue
// Created Time: Tue Jul 22 18:51:59 2014
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
class DivisorsPower {
public:
	LL mysqrt(LL n) {
		LL l = 0, r = INF;
		while (l + 1 < r) {
			LL mid = (l + r) >> 1;
			if (mid*mid > n) r = mid; else l = mid;
		}
		return l;
	}
	bool check(int n, int d, LL h) {
		LL tmp = 1;
		for (int i = 0; i < d; ++i) {
			if (tmp > h / n) return 0;
			tmp *= n;
		}
		return tmp == h;
	}
	int div(int n) {
		int res = 0;
		for (int d = 1; d * d <= n; ++d) if (n % d == 0) {
			++res;
			if (d * d != n) ++res;
		}
		return res;
	}
	int f[MaxN];
	long long findArgument(long long n) {
		LL x = mysqrt(n);
		LL res = LINF;
		if (x * x == n) {
			if (div(x) == 2) res = min(res, x);
		}
		for (int i = 1; i < MaxN; ++i) {
			for (int j = i; j < MaxN; j += i) f[j] += 1;
		}
		for (int i = 1; i < MaxN; ++i) {
			if (check(i, f[i], n)) {
				res = min(res, (LL) i);
				break;
			}
		}
		if (res == LINF) return -1;
		return res;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	DivisorsPower *obj;
	long long answer;
	obj = new DivisorsPower();
	clock_t startTime = clock();
	answer = obj->findArgument(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	long long p0;
	long long p1;
	
	{
	// ----- test 0 -----
	p0 = 4ll;
	p1 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10ll;
	p1 = -1ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 64ll;
	p1 = 4ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10000ll;
	p1 = 10ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 2498388559757689ll;
	p1 = 49983883ll;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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


