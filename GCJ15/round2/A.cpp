#include <bits/stdc++.h>
using namespace std;


int visX[111];
int visY[111];
char MAP[111][111];

const int ud[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {


	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);

		int R, C; scanf("%d %d", &R, &C);
		memset(visX, 0, sizeof visX);
		memset(visY, 0, sizeof visY);

		for (int i = 0; i < R; ++i) {
			scanf("%s", MAP[i]);
			for (int j = 0; j < C; ++j) {
				if (MAP[i][j] != '.') {
					++visX[i];
					++visY[j];
				}
			}
		}

		bool can = true;

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) {
				if (MAP[i][j] == '.') continue;
				if (visX[i] == 1 && visY[j] == 1) {
					can = false;
				}
			}

		if (!can) puts("IMPOSSIBLE");
		else {
			int ans = 0;
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j) {
					if (MAP[i][j] == '.') continue;
					int d = 0;
					if (MAP[i][j] == '^') {
						d = 0;
					}
					if (MAP[i][j] == '>') {
						d = 1;
					}
					if (MAP[i][j] == 'v') {
						d = 2;
					}
					if (MAP[i][j] == '<') {
						d = 3;
					}
					bool find = false;
					for (int t = 0, x = i, y = j; t < max(R, C); ++t) {

						x += ud[d][0];
						y += ud[d][1];
						if (x < 0 || y < 0 || x >= R || y >= C) break;
						if (MAP[x][y] != '.') {
							find = true;
						}
					}
					if (!find) ++ans;
				}
			printf("%d\n", ans);
		}

	}

	return 0;
}
