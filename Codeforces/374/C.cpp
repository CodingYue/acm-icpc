#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int mod = (int) 1e9 + 7;

struct Tnode {
	int mat[2][2];
	int summary[2][2];
} T[444444];

void clear(int a[][2]) {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) a[i][j] = 0;
}
void unit(int a[][2]) {
	clear(a);
	for (int i = 0; i < 2; ++i) a[i][i] = 1;
}
void init(int a[][2]) {
	clear(a);
	a[0][0] = 1;
	a[0][1] = 0;
}
void make_fib(int a[][2]) {
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 0;
}

void mul(int a[][2], int b[][2]) {
	int tmp[2][2];
	clear(tmp);
	tmp[0][0] = ((long long) a[0][0] * b[0][0] + (long long) a[0][1] * b[1][0]) % mod;
	tmp[0][1] = ((long long) a[0][0] * b[0][1] + (long long) a[0][1] * b[1][1]) % mod;
	tmp[1][0] = ((long long) a[1][0] * b[0][0] + (long long) a[1][1] * b[1][0]) % mod;
	tmp[1][1] = ((long long) a[1][0] * b[0][1] + (long long) a[1][1] * b[1][1]) % mod;
	memcpy(a, tmp, sizeof tmp);
}
void fpow(int res[][2], int times, int mod) {
	int base[2][2];
	make_fib(base);
	for (int t = times; t; t >>= 1) {
		if (t & 1) mul(res, base);
		mul(base, base);
	}
}

int a[111111];

#define lch(n) ((n) << 1)
#define rch(n) (((n) << 1) + 1)

void plus_mat(int res[][2], int a[][2], int b[][2]) {
	int tmp[2][2];
	clear(tmp);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			tmp[i][j] = (a[i][j] + b[i][j]) % mod;
		}
	memcpy(res, tmp, sizeof tmp);
}

void update(int p) {
	int res_l[2][2];
	int res_r[2][2];
	memcpy(res_l, T[lch(p)].summary, sizeof res_l);
	memcpy(res_r, T[rch(p)].summary, sizeof res_r);
	mul(res_l, T[lch(p)].mat);
	mul(res_r, T[rch(p)].mat);
	plus_mat(T[p].summary, res_l, res_r);
}

void build(int p, int l, int r) {
	unit(T[p].mat);
	if (l == r) {
		fpow(T[p].mat, a[l], mod);
		init(T[p].summary);
		return;
	}
	int mid = (l + r) / 2;
	build(lch(p), l, mid);
	build(rch(p), mid+1, r);
	update(p);
}

void query(int p, int i, int j, int l, int r, int res[][2]) {
	if (i <= l && r <= j) {
		memcpy(res, T[p].summary, sizeof(T[p].summary));
		mul(res, T[p].mat);
		return;
	}
	int mid = (l+r) / 2;
	int res_l[2][2];
	int res_r[2][2];
	clear(res_l);
	clear(res_r);
	if (i <= mid) {
		query(lch(p), i, j, l, mid, res_l);
	}
	if (j > mid) {
		query(rch(p), i, j, mid+1, r, res_r);
	}
	plus_mat(res, res_l, res_r);
	mul(res, T[p].mat);
}

void modify(int p, int i, int j, int l, int r, int x) {
	if (i <= l && r <= j) {
		int mul_mat[2][2];
		unit(mul_mat);
		fpow(mul_mat, x, mod);
		mul(T[p].mat, mul_mat);
		return;
	}
	int mid = (l + r) / 2;
	if (i <= mid) modify(lch(p), i, j, l, mid, x);
	if (j > mid) modify(rch(p), i, j, mid+1, r, x);
	update(p);
}

int main(void) {

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			int x = 0; scanf("%d", &x);
			modify(1, l, r, 1, n, x);
		} else {
			int res[2][2];
			query(1, l, r, 1, n, res);
			printf("%d\n", res[0][1]);
		}

	}
	

	return 0;
}