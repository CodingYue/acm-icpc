#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int et = 0;
string s[100005];
struct Node {
	int size;
	Node *ch[26];
} arr[100005], *root;
Node *newNode() {
	return &arr[et++];
}
void insert(string s) {
	int n = s.size();
	Node *now = root;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		now->size++;
		if (!now->ch[c]) {
			now->ch[c] = newNode();
		}
		now = now->ch[c];
	}
	now->size++;
}
int ans = 0;
bool add = 0;
void del(string s) {
	int n = s.size();
	int tmp = 0;
	Node *now = root;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		--now->size;
		if (now->size == 0 && add == 0) {
			add = 1;
			ans += tmp;
		}
		now = now->ch[c];
		++tmp;
	}
	--now->size;
	if (!add) ans += tmp;
}
int main() {
//	freopen("Cin", "r", stdin);
	int n; scanf("%d", &n);
	
	root = newNode(); root->size = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		insert(s[i]);
	}
	for (int i = 0; i < n; ++i) {
		add = 0;
		del(s[i]);
	}
	printf("%d.000000\n", ans);

	return 0;
