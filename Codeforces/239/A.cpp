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

int main()
{
	//freopen("in","r",stdin);

	int a, b;
	scanf("%d %d", &a, &b);
	vector<PII> X, Y;
	for (int i = -a + 1; i <= a - 1; ++i) if (i) {
		int x = (int) (sqrt(a * a - i * i) + 0.01);
		if (x * x == a * a - i * i && x) {
			X.push_back(make_pair(i, x));
		}
	}
	for (int i = -b + 1; i <= b - 1; ++i) if (i) {
		int x = (int) (sqrt(b * b - i * i) + 0.01);
		if (x * x == b * b - i * i && x) {
			Y.push_back(make_pair(i, x));
		}
	}
	for (int i = 0; i < (int) X.size(); ++i)
	for (int j = 0; j < (int) Y.size(); ++j) {
		PII p1 = X[i], p2 = Y[j];
		if (p1.first * p2.first + p1.second * p2.second) continue;
		if (p1.first != p2.first && p1.second != p2.second) {
			puts("YES");
			printf("%d %d\n%d %d\n%d %d\n", 0, 0, p1.first, p1.second, p2.first, p2.second);
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}

