#include <bits/stdc++.h>
using namespace std;

queue<int> que[333333];
bool has_read[311111];

int main(void) {

	int n, q;
	scanf("%d %d", &n, &q);

	int idx = 0;
	queue<int> all_que;
	int ans = 0;
	for (int i = 0; i < q; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x;
			scanf("%d", &x);
			all_que.push(idx);
			que[x].push(idx++);
			++ans;
		} else
		if (type == 2) {
			int x; scanf("%d", &x);
			while (!que[x].empty()) {
				int first = que[x].front(); que[x].pop();
				if (!has_read[first]) {
					has_read[first] = true;
					--ans;
				}
			}
		} else {
			int t; scanf("%d", &t);
			while (true) {
				if (all_que.empty()) break;
				int first = all_que.front(); 
				if (first < t) {
					if (!has_read[first]) {
						has_read[first] = true;
						--ans;
					}
					all_que.pop();
				} else {
					break;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}