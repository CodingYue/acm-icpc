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

char A[1111][1111];
int n,m;
int l[1111], r[1111];

int check() {

	For(i,1,n) {
		l[i] = r[i] = -1;
		A[i][0] = '.';
		For(j,1,m) if (A[i][j] != A[i][j - 1]) {
			if (l[i] == -1) l[i] = j;
			else if (r[i] == -1) r[i] = j - 1;
			else {
				return INF;
			}
		}
		if (A[i][m] == 'X') r[i] = m;
	}

	l[n + 1] = r[n + 1] = -1;

	int first = 0;
	For(i,1,n) if (l[i] != -1) {
		first = i; break ;
	}
	
	int width = r[first] - l[first] + 1;
	int height = -INF;
	For(i,first,n) {
		int p = i;
		while (l[p + 1] == l[i] && r[p + 1] == r[i] && p < n) {
			++p;
		}
		if (l[i] == -1) {
			if (l[p + 1] != -1) {
				return INF;
			}
			i = p;
			continue ;
		}
		int cnt = p - i + 1;
		if (l[p + 1] != -1) {
			int inter = r[p] - l[p + 1] + 1;
			if (inter != width) {
				return INF;
			}
		}
		if (r[i] - l[i] + 1 != width) {
			if (height == -INF) height = cnt;
			else if (height != cnt) return INF;
		}
		i = p;
	}

	if (height == -INF) height = 1;
	return height * width;

}

int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	cin >> n >> m;
	For(i,1,n) {
		scanf(" %s", A[i] + 1);
	}
	int ans = INF;
	For(TIME,0,1) {

		ans = min(ans, check());

		For(i,1,max(n,m)) For(j,1,i - 1) swap(A[i][j], A[j][i]);
		swap(n,m);
	}
	if (ans == INF) puts("-1");
	else cout << ans << endl;
	return 0;
}
