#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

int bit[111];

int main(void) {

	int cases; scanf("%d", &cases);
	int cas = 0;

	while (cases--) {

		int n = 0; scanf("%d", &n);

		printf("Case #%d: ", ++cas);
		if (n == 0) {
			printf("0 0\n");
			continue;
		}
		int Max = n, Min = n;

		int len = 0;
		for (int t = n; t; t /= 10) bit[++len] = t % 10;
		for (int i = 1; i < len; ++i) {
			if (bit[i] == 0) continue;
			swap(bit[i], bit[len]);
			int x = 0;
			for (int i = len; i >= 1; --i) x = x * 10 + bit[i];
			Max = max(Max, x);
			Min = min(Min, x);
			swap(bit[i], bit[len]);
		}
		printf("%d %d\n", Min, Max);
	}

	return 0;
}
