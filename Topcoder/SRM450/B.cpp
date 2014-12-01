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

typedef long long LL;

class StrongEconomy {
public:
	LL div_ceil(LL a, LL b) {
		if (a <= 0) return 0;
		return a / b + (a % b != 0);
	}
	void justify(LL &a, LL &b, LL canbuy) {
	
		LL ta = a;
		a = min(a + canbuy, b);
		canbuy -= (a - ta);
		ta = a;
		a += canbuy / 2;
		b += canbuy - (a - ta);
	}
	long long earn(long long a, long long b, long long price, long long target) {
		// n * k >= target
		if (a >= div_ceil(target, b)) return 1;

		if (a > b) swap(a, b);
		LL round = 0;
		LL earn = 0;
		LL ans = div_ceil(target, a*b);
		for (LL x = 0; x <= 3000000; ) {
		
			
			if (a * b > target) break;
//			if (x * price > target) break;
			LL need = div_ceil(price-earn, a*b);
			round += need;
			earn += a * b * need;
			LL canbuy = earn / price;
			earn %= price;
			justify(a, b, canbuy);
			x += canbuy;
			ans = min(ans, round + (a >= div_ceil(target-earn, b) ? 1 : div_ceil(target - earn, a * b)));
//			if (a * b > target) break;
		}

		return ans;
	}
};
