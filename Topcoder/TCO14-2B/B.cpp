#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class SumAndProductPuzzle {
public:
	int pm;
	int prime[5111111];
	int cnt[5111111];
	pair<int, int> choose[5111111];
	bool flag[5111111];
	bool can[5111111];
	void gen_prime(int n) {
		flag[1] = 1;
		for (int i = 2; i <= n; ++i) {
			if (!flag[i]) {
				prime[pm++] = i;
			}
			for (int j = 0; j < pm && (long long) prime[j] * i <= n; ++j) {
				flag[i * prime[j]] = 1;
				if (i % prime[j] == 0) break;
			}
		}
	}
	long long getSum(int A, int B) {
		int n = 5000000;
		gen_prime(n);
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				if ((long long) i * j > n) break;
				if (flag[i + j - 1]) {
					++cnt[i * j];
					choose[i * j] = make_pair(i, j);
				}
			}
		}
		for (int i = 1; i <= n; ++i) if (cnt[i] == 1) {
			can[choose[i].first + choose[i].second] = 1;
		}
		long long res = 0;
		for (int i = A; i <= B; ++i) if (can[i]) res += i;
		return res;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SumAndProductPuzzle *obj;
	long long answer;
	obj = new SumAndProductPuzzle();
	clock_t startTime = clock();
	answer = obj->getSum(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	int p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 30;
	p1 = 33;
	p2 = 33ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 8;
	p1 = 11;
	p2 = 19ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 40;
	p1 = 43;
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 47;
	p1 = 74;
	p2 = 168ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 2;
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
