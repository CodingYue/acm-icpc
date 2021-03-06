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


class AB {
public:
	int pre[55][55][55*55/2];

	string createString(int N, int K) {
		memset(pre, -1, sizeof pre);
		pre[0][0][0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k <= K; ++k) if (pre[i][j][k] != -1) {
					int a = j;
					pre[i+1][j+1][k] = 0;
					pre[i+1][j][k+a] = 1;
				}
			}
		}
		string ans = "";
		int x = -1;
		for (int j = 0; j <= N; ++j) if (pre[N][j][K] != -1) {
			x = j;
			break;
		}
		if (x == -1) return ans;
		for (int p = N; p >= 1; --p) {
			if (pre[p][x][K] == 0) {
				ans += "A";
				--x;
			}
			else {
				ans += "B";
				K -= x;
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	AB *obj;
	string answer;
	obj = new AB();
	clock_t startTime = clock();
	answer = obj->createString(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = "ABB";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 0;
	p2 = "BA";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 8;
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 12;
	p2 = "BAABBABAAB";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
