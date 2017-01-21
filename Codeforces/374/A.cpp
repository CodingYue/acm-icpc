#include <bits/stdc++.h>
using namespace std;

int n, T;
char str[222222];

int main(void) {

	scanf("%d %d", &n, &T);

	scanf("%s", str+1);
	int pos_dot = -1;
	int pos_round = -1;
	for (int i = 1; i <= n; ++i) {
		if (str[i] == '.') pos_dot = i;
		if (pos_dot != -1) {
			if (str[i] >= '5' && str[i] <= '9') {
				pos_round = i;
				break;
			}
		}
	}
	if (pos_round == -1) {
		puts(str+1);
	} else {
		str[pos_round+1] = '\0';
		for (int i = pos_round; i > pos_dot && T > 0; --T, --i) {
			int add = 0;
			if (str[i] >= '5') {
				add = 1;
				str[i] = '\0';
			}
			if (str[i] == '9'+1) {
				++T;
			}
			if (i-1 == pos_dot) {
				str[i-2] += add;
			} else {
				str[i-1] += add;
			}
		}
		for (int i = pos_dot-1; i > 0; --i) {
			if (str[i] == '9' + 1) {
				str[i] = '0';
				str[i-1] += 1;
			}
		}
		if (str[pos_dot+1] == '\0') str[pos_dot] = '\0';
		if (str[0] == 1) {
			str[0] = '1';
			puts(str);
		} else {
			puts(str+1);
		}
	}

	return 0;
}