// File Name: 250.cpp
// Author: YangYue
// Created Time: Sun Apr 13 00:01:46 2014
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
class EllysSortingTrimmer {
public:
	char s[111];
	string getMin(string S, int L) {
		for (int i = 0; i < S.size(); ++i) s[i] = S[i];
		for (int i = S.size() - L; i >= 0; --i) {
			sort(s + i, s + i + L);
		}
		string res = "";
		for (int i = 0; i < L; ++i) res += s[i];
		return res;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	EllysSortingTrimmer *obj;
	string answer;
	obj = new EllysSortingTrimmer();
	clock_t startTime = clock();
	answer = obj->getMin(p0, p1);
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
	
	string p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "ABRACADABRA";
	p1 = 5;
	p2 = "AAAAA";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ESPRIT";
	p1 = 3;
	p2 = "EIP";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "BAZINGA";
	p1 = 7;
	p2 = "AABGINZ";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	p1 = 13;
	p2 = "ABCDEFGHIJKLM";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "GOODLUCKANDHAVEFUN";
	p1 = 10;
	p2 = "AACDDEFGHK";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
	p1 = 21;
	p2 = "AAAAAAAAABBDDDDDDDEEI";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "TOPCODER";
	p1 = 3;
	p2 = "CDT";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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


