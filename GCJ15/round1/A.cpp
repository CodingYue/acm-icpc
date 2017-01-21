#include<bits/stdc++.h>

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

int q[MaxN], vis[MaxN], d[MaxN];
int main() {
	int hd = 0, tl = 1;
	vis[q[1] = 1] = true; d[1] = 0;
	while (hd < tl) {
		int vex = q[++hd]; if (vex > 1000000) continue ; 
		if (!vis[vex + 1]) { vis[q[++tl] = vex + 1] = true; d[vex + 1] = d[vex] + 1; }
		int nex = 0, tmp = vex;
		while (tmp) {
			nex = nex * 10 + tmp % 10; 
			tmp /= 10;
		}
		if (!vis[nex]) { vis[q[++tl] = nex] = true; d[nex] = d[vex] + 1; }
	}
	int T; cin >> T;
	For(TK,1,T) {
		int c;
		scanf("%d", &c); 
		printf("Case #%d: %d\n", TK, d[c] + 1);
	}
	return 0;
}
