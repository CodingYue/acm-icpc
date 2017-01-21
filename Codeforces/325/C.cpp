#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string ans;

string ll_to_string(LL x) {
	string ans;
	vector<int> res;
	for (; x; x /= 10) res.push_back(x % 10);
	reverse(res.begin(), res.end());
	for (auto t : res) ans += t + '0';
	return ans;
}

void fuck(LL x, LL y, bool who) {
	if (x < y) {
		fuck(y, x, !who);
		return;
	}
	if (y == 1) {
		if (x == 1) return;
		ans += ll_to_string(x-1);
		ans += (char) (who + 'A');
	} else {
		ans += ll_to_string(x/y);
		ans += (char) (who + 'A');
		fuck(y, x%y, !who);
	}

}

int main(void) {

	LL x, y;
	cin >> x >> y;
	if (__gcd(x, y) != 1) {
		puts("Impossible");
	} else {
		ans = "";
		fuck(x, y, 0);
		cout << ans << endl;
	}


	return 0;
}