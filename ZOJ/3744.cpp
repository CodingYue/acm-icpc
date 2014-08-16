#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}

double f(double x) {
	return 1 + 8./sqrt(7.)*sqrt(x)*sin(sqrt(7.)/2.*log(x));
}

int main() {
//	freopen("Hin","r",stdin);
	double x = 0;
	char c;
	while (scanf("%lf%c", &x, &c) != EOF) {
		if (x < 25) {
			printf("%.12f\n", 0);
		} else {
			x = sqrt(x * 0.04);
			printf("%.12f\n", f(x));
		}
	}

	return 0;
}
