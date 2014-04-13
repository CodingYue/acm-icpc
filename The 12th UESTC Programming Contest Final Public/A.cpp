#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100005], b[100005], c[100005];

int main() {
	//freopen("Ain","r",stdin);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (i % 2 == 0) b[i / 2] = a[i];
		else c[i / 2] = a[i];
	}
	sort(a, a + n);
	sort(b, b + n - n / 2);
	sort(c, c + n / 2);
	
	for (int i = 0; i < n; ++i) {
		int now = 0;
		if (i % 2 == 0) now = b[i / 2];
		else now = c[i / 2];
		if (now != a[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	
	return 0;
