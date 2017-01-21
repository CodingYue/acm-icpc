#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int uk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char MAP[1111][1111];


pii que[1111111];
int dist[4][1111][1111];
bool inque[1111111];
bool vis[1111][1111];

int isdigit(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;
}

int main(void) {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", MAP[i]);
	}

	
	for (int state = 1; state <= 3; ++state) {
		memset(vis, 0, sizeof vis);
		queue<pii> que;
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) if (MAP[x][y] - '0' == state) {
				que.push(pii(x,y));
			}
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			vis[x][y] = true;
			que.pop();
			for (int k = 0; k < 4; ++k) {
				int nx = uk[k][0] + x;
				int ny = uk[k][1] + y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (!isdigit(MAP[nx][ny])) continue;
				if (!vis[nx][ny]) {
					que.push(pii(nx, ny));
				}
			}
		}
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				if (vis[x][y]) {
					que.push(pii(x, y));
					dist[state][x][y] = 0;
				} else {
					dist[state][x][y] = 111111111;
				}
			}
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int k = 0; k < 4; ++k) {
				int nx = uk[k][0] + x;
				int ny = uk[k][1] + y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (MAP[nx][ny] == '#') continue;
				if (!vis[x][y] && isdigit(MAP[x][y]) && MAP[nx][ny] == '.') continue;
				int w = 1-isdigit(MAP[nx][ny]);
				if (dist[state][nx][ny] > 1000000) {
					dist[state][nx][ny] = dist[state][x][y] + w;
					que.push(pii(nx, ny));
				}
			}
		}
	}

	int ans = 0x0f7f7f7f;

	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y) {

			if (!isdigit(MAP[x][y]))

				ans = min(ans, dist[1][x][y] + dist[2][x][y] + dist[3][x][y] - 2);
			else ans = min(ans, dist[1][x][y] + dist[2][x][y] + dist[3][x][y]);
		}
	if (ans > 1000000) {
		puts("-1");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}