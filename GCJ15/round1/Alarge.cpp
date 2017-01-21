#include<bits/stdc++.h>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

long long rev(long long x) {
	long long ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

set<long long> powers;
long long pw[22];
long long solve(long long x) {
	long long cur = 1, cursteps = 1, ret = x;
	long long curpower = 1;
	while (cur <= x) {
		ret = min(ret, cursteps + x - cur);
		if (cur == x) break ;
		long long up = *powers.upper_bound(cur);
		if (up <= x) {
			if (cur == 1) {
				cur = 10; ++curpower; cursteps = 10;
				continue ;
			}
			cur += pw[curpower / 2] - 1; cur = rev(cur);
			cursteps += pw[curpower / 2] + up - cur; cur = up;
			++curpower;
		} else {
			if (x % 10 == 0) {
				++cursteps; --x;
			}
			long long tmp = rev(x);
			tmp %= pw[curpower / 2];
			cur += tmp; cursteps += tmp;
			cur = rev(cur); ++cursteps;
			cursteps += x - cur; cur = x;
		}
	}
	return ret;
}

int main() {
	long long c = 1; pw[0] = 1;
	For(i,1,18) {
		powers.insert(c);
		c = c * 10; pw[i] = c;
	}
	int T = 0; cin >> T;
	For(TK,1,T) {
		long long c;
		cin >> c;
		printf("Case #%d: %lld\n", TK, solve(c));
	}
	return 0;
}
