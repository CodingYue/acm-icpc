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
#define UPD(a,b) { a = (a + (b)); }

int A,B,K;
int calc[55][2][2][2];
long long f[55][2][2][2];
long long dp(int i, int w1, int w2, int w3) {
	if (i == 0) {
		return w3;
	}
	if (calc[i][w1][w2][w3]) return f[i][w1][w2][w3];
	calc[i][w1][w2][w3] = true;
	f[i][w1][w2][w3] = 0;
	int a0 = A >> i - 1 & 1;
	int b0 = B >> i - 1 & 1;
	int k0 = K >> i - 1 & 1;
	//11
	if ((a0 || w1) && (b0 || w2) && (k0 || w3)) {
		UPD(f[i][w1][w2][w3], dp(i - 1,w1,w2,w3));
	}
	//10
	if (a0 || w1) {
		UPD(f[i][w1][w2][w3], dp(i - 1,w1,w2 || b0, w3 || k0));
	}
	//01
	if (b0 || w2) {
		UPD(f[i][w1][w2][w3], dp(i - 1,w1 || a0, w2, w3 || k0));
	}
	UPD(f[i][w1][w2][w3], dp(i - 1,w1 || a0, w2 || b0, w3 || k0));
	return f[i][w1][w2][w3];
}

int main() {
	freopen("in","r",stdin);
	freopen("B.out","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) { 
		cin >> A >> B >> K;
		--A; --B;
		Fill(calc,0);
		printf("Case #%d: ",TTT);
		cout << dp(31,0,0,0) << endl;
	}
	return 0;
}


