#include <bits/stdc++.h>
using namespace std;


int a[17][17];

int main(void) {


	int cases; scanf("%d", &cases);

	for (int cas = 1; cas <= cases; ++cas) {
		printf("Case #%d: ", cas);

		int R, C;
		scanf("%d %d", &R, &C);
		int n = 0; scanf("%d", &n);

		int ans = 99999;

		for (int s = 0; s < (1<<(R*C)); ++s) {
			memset(a, 0, sizeof a);
			if (__builtin_popcount(s) == n) {
				for (int i = 0; i < R*C; ++i) if (s >> i & 1) {
					int x = i/C;
					int y = i%C;
					a[x][y] = true;
				}
				int sum = 0;
				for (int i = 0; i < R; ++i)
					for (int j = 0; j < C; ++j) if (a[i][j]) {
						if (i && a[i-1][j]) ++sum;
						if (j && a[i][j-1]) ++sum;
					}
				ans = min(ans, sum);
				
			}
		}
		printf("%d\n", ans);

			
	}

	return 0;
}
