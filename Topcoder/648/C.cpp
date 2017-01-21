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

const int mod = (int) 1e9 + 7;

class Fragile {
public:

	int f[55][55];

	int calc(int n, int K) {
		if (n == 1 && K == 0) return 1;
		if (f[n][K] != -1) return f[n][K];

		f[n][K] = 0;
		if (K == 0) {
			int res = 0;
			for (int k = 1; k <= K; ++k) res = (res + f[n][K]) % mod;
		}

	}

	int countGraphs(int N, int K) {
		
	}
};

