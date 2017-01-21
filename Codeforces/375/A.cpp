#include <bits/stdc++.h>
using namespace std;



int main(void) {

	int x[3];
	for (int i = 0; i < 3; ++i) scanf("%d", &x[i]);
	sort(x, x + 3);
	printf("%d\n", x[1]-x[0] + x[2]-x[1]);

	return 0;
}