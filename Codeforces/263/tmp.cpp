#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int tree[MaxN];
void ins(int x, int val) {
	for (int z = x; z <= 1000000; z += z & -z) tree[z] += val;
}

int _ask(int x) {
	int ret = 0;
	if (x < 0) return 0;
	for (int z = x; z; z -= z & -z) ret += tree[z];
	return ret;
}

int ask(int l, int r) {
	return _ask(r) - _ask(l);
}

int n, Q;
int main() {
	freopen("in","r",stdin);
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	cin >> n >> Q;
	Fill(tree,0);
	For(i,1,n) ins(i, 1);
	int l = 0, r = n;
	bool rev = false ;
	For(QQ,1,Q) {
		int op, p, tl, tr;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &p);
			int tp = p;
			int curlen = r - l;
			if (rev) p = curlen - p;
			if (tp * 2 > curlen) rev ^= 1;
			if (p * 2 > curlen) {
				Cor(i,r - 1,l + p) {
					int c = ask(i, i + 1);
					ins(l + p - (i + 1 - (l + p)) + 1, c);
				}
				r = l + p;
			} else {
				For(i,l,l + p - 1) {
					int c = ask(i, i + 1);
					ins(l + p + (l + p - i), c);
				}
				l += p;
			}
			/*For(i,l,r - 1) {
				int c = ask(i, i + 1);
				printf("%d ",c);
			}
			puts("");
			*/
		}
		if (op == 2) {
			scanf("%d%d", &tl, &tr);
			int curlen = r - l;
			if (rev) {
				tl = curlen - tl, tr = curlen - tr;
				swap(tl,tr);
			}
			int ans = ask(l + tl, l + tr);
			printf("%d\n", ans);
		}
	}
	return 0;
}
