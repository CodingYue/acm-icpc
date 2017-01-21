#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

typedef long long LL;

map<pii, pii> best;

int pow3[14];
int v[26][4];
int state[333];

const char fuck[] = {'L', 'M', 'W'};

int main(void) {

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j) scanf("%d", &v[i][j]);

	int halfn = n/2;
	pow3[0] = 1;
	for (int i = 1; i <= n/2+1; ++i) pow3[i] = pow3[i-1] * 3;

	for (int mask = 0; mask < pow3[halfn]; ++mask) {

		int number[3] = {0, 0, 0};

		for (int t = 0, tmp = mask; t < halfn; tmp /= 3, ++t) state[t] = tmp % 3;

		for (int i = 0; i < halfn; ++i) {
			for (int j = 0; j < 3; ++j) if (j != state[i]) {
				number[j] += v[i][j];
			}
		}

		pii tmp = pii(number[0] - number[1], number[0] - number[2]);

		if (!best.count(tmp)) {
			best[tmp] = pii(number[0], mask);
		} else {
			best[tmp] = max(best[tmp], pii(number[0], mask));
		}

	}

	int ans = 0;
	LL bestmask = -1;

	for (int mask = 0; mask < pow3[n-halfn]; ++mask) {

		int number[3] = {0,0,0};
		for (int t = 0, tmp = mask; t < n-halfn; ++t, tmp /= 3) state[t] = tmp % 3;

		for (int i = 0; i < n-halfn; ++i) {
			for (int j = 0; j < 3; ++j) if (j != state[i]) {
				number[j] += v[i+halfn][j];
			}
		}

		pii tmp = pii(number[1] - number[0], number[2] - number[0]);

		if (!best.count(tmp)) continue;

		pii cur = best[tmp];

		if (bestmask == -1  || ans < cur.first + number[0]) {
			ans = cur.first + number[0];
			bestmask = (LL) mask * pow3[halfn] + cur.second;
		}

	}

	if (bestmask == -1) {
		puts("Impossible");
	} else {
		for (int t = 0; t < n; ++t, bestmask /= 3) state[t] = bestmask % 3;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) if (state[i] != j) {
				putchar(fuck[j]);
			}
			puts("");
		}
	}

	return 0;
}