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


class OrderedNim {
public:

	int win[55][2];

	string winner(vector <int> layout) {
		int n = layout.size();
		
		
		win[n][1] = 1;
		
		for (int i = n - 1; i >= 0; --i) {
		
			win[i][0] = win[i+1][1];
			if (layout[i] > 1) {
			
				win[i][0] |= win[i+1][0];
				win[i][1] = 0;
			
			} else {
				win[i][1] = win[i+1][0];
			}
		}
		return win[0][0] ? "Alice" : "Bob";
	}
};
