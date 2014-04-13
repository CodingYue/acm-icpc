#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000000;

string s;
bool used[26];

int main() {

	cin >> s;
	int use = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '?') {
			if (!used[s[i] - 'a']) ++use;
			used[s[i] - 'a'] = 1;
		} else ++cnt;
	}
	int l = -1, r = -1;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '?') {
		l = i; break;
	}
	for (int i = s.size() - 1; i >= 0; --i) if (s[i] == '?') {
		r = i; break;
	}
	
	int lc = -1, rc = -1;
	if (l > 0) lc = s[l-1];
	if (r < s.size() - 1) rc = s[r+1];
	if (lc != -1 && lc == rc) {
		if (use % 2 == 0) puts("No");
		else puts("Yes");
		return 0;
	}
	if (use % 2 == 1) puts("Yes");
	else {
		if ((use + cnt) % 2 == 1) puts("Yes");
		else puts("No");
	}
	
	return 0;
