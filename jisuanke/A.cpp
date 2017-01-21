#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))

const int INF = (int) 1e9+1;

int x1, x2, Y1, y2, z1, z2;
int check(int p1, int p2, int p3) {
	int lx = 0;
	int rx = 0;
	int ly = 0;
	int ry = 0;
	int lz = 0;
	int rz = 0;
	if (p1 < 0) {
		lx = -INF;
		rx = 0;
	} else {
		lx = 0;
		rx = INF;
	}
	if (p2 < 0) {
		ly = -INF;
		ry = 0;
	} else {
		ly = 0;
		ry = INF;
	}
	if (p3 < 0) {
		lz = -INF;
		rz = 0;
	} else {
		lz = 0;
		rz = INF;
	}
	lx = max(lx, x1);
	rx = min(rx, x2);
	ly = max(ly, Y1);
	ry = min(ry, y2);
	lz = max(lz, z1);
	rz = min(rz, z2);
	if (lx >= rx || ly >= ry || lz >= rz) return 0;
	return (rx - lx) * (ry - ly) * (rz - lz);
}
int main(void) {

	int cases; scanf("%d", &cases);
	while (cases--) {

		scanf("%d %d %d %d %d %d", &x1, &x2, &Y1, &y2, &z1, &z2);
		printf("%d ", check(1, 1, 1));
		printf("%d ", check(-1, 1, 1));
		printf("%d ", check(-1, -1, 1));
		printf("%d ", check(1, -1, 1));
		printf("%d ", check(1, 1, -1));
		printf("%d ", check(-1, 1, -1));
		printf("%d ", check(-1, -1, -1));
		printf("%d\n", check(1, -1, -1));

	}

	return 0;
}
