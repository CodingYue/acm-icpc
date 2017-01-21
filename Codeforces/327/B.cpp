#include <bits/stdc++.h>
using namespace std;



int main(void) {

	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1,&x2, &y2);
	double vmax, t;
	scanf("%lf %lf", &vmax, &t);
	double vx, vy, wx, wy;
	scanf("%lf %lf %lf %lf", &vx, &vy, &wx, &wy);

	double l = 0;
	double r = 1e9;
	for (int TIME = 0; TIME < 200; ++TIME) {
		double mid = (l+r) / 2;

		double x = x1 + min(t, mid) * vx;
		double y = y1 + min(t, mid) * vy;
		x = x + max(0., mid-t) * wx;
		y = y + max(0., mid-t) * wy;

		double T = sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y)) / vmax;
		if (T < mid) r = mid;
		else l = mid;

	}
	printf("%.10f\n", l);

	return 0;
}