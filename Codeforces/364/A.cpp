#include <bits/stdc++.h>
using namespace std;

int n, k;
double l, v1, v2;
bool check(double T) {
	int TIMES = n / k + (n % k != 0);
	for (int p = 0; p < TIMES; ++p) {
		double t = (v2 * T - l) / (v2 - v1);
		if (t < 0) return false;
		T = t;
	}
	return true;
}

int main(void) {


	scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);

	double L = 0;
	double R = 1e9;

	printf("%d\n", check(4.5));

	for (int TIME = 0; TIME < 100; ++TIME) {
		double mid = (L + R) / 2;
		if (check(mid)) R = mid;
		else L = mid;
	}
	printf("%.10f\n", R);

	return 0;
}