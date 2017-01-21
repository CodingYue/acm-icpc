#include <bits/stdc++.h>
using namespace std;

typedef pair<long double, long double> pdd;
const double eps = 1e-8;

int dcmp(long double x) { return x < -eps ? -1 : x > eps; }

pdd A[1111];


int main(void) {

	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		printf("Case #%d: ", cas);

		int n = 0;
		long double V, X;
		cin >> n >> V >> X;
		bool bigger = false;
		bool lower = false;
		bool equal = false;

		for (int i = 0; i < n; ++i) {
			double R, T;
			scanf("%lf %lf", &R, &T);
			if (T > X+eps) bigger = true;
			if (T < X-eps) lower = true;
			if (dcmp(T-X) == 0) equal = true;
			A[i] = pdd(T, R);
		}
		if ((!bigger || !lower) &&  !equal) {
			puts("IMPOSSIBLE");
			continue;
		}
		sort(A, A + n);

		long double sumR = 0;
		long double curT = 0;
		for (int i = 0; i < n; ++i) {
			sumR += A[i].second;
			curT += (A[i].first - X) * A[i].second;
		}
		if (dcmp(curT) == 0) {
			double ans = V / sumR;
			printf("%.10f\n", ans);
			continue;
		}

		int cmp = -1;
		if (dcmp(curT) > 0) {
			reverse(A, A + n);
			cmp = 1;
		}

		for (int i = 0; i < n; ++i) {
			long double tmp = (A[i].first - X) * A[i].second;
			if (dcmp(curT - tmp) == cmp) {
				sumR -= A[i].second;
				curT -= tmp;
			} else {
				sumR -= curT / (A[i].first-X);
				break;
			}
		}

		if (dcmp(sumR) <= 0) {
			puts("IMPOSSIBLE");
		} else {
			double ans = V / sumR;
			printf("%.10f\n", ans);
		}

	}

	return 0;
}
