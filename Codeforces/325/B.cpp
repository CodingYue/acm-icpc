#include <bits/stdc++.h>
using namespace std;

char MAP[3][111];
bool f[111][3];

int main(void) {

	


	int cases; scanf("%d", &cases);
	while (cases--) {
		bool OK = false;	
		memset(f, 0, sizeof f);

		int n = 0;
		int k = 0;
		scanf("%d %d", &n, &k);

		for (int i = 0; i < 3; ++i) scanf("%s", MAP[i]);

		int st = 0;
		for (int i = 0; i < 3; ++i) if (MAP[i][0] == 's') st = i;
		f[0][st] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) if (f[i][j]) {
				if (i+1<n && MAP[j][i+1] != '.') continue;
				for (int k = 0; k < 3; ++k) {
					if (abs(k-j) > 1) continue;
					if (i+1<n && MAP[k][i+1] != '.') continue;
					if (i+2<n && MAP[k][i+2] != '.') continue;
					if (i+3<n && MAP[k][i+3] != '.') continue;
					if (i+3 >= n) OK = true;
					f[i+3][k] = true;
				}
			}
		}

		if (OK) puts("YES");
		else puts("NO");

	}


	return 0;
}