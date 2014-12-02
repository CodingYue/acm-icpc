#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = (int) 1e9 + 7;

typedef long long LL;

vector<int> edges[222];

int size[222];
int f[222][222];
int g[222][222];
int sumf[222][222];
int sumg[222][222];
int C[222][222];

void add(int &x, int v) {
	x += v;
	x %= mod;
}
inline int mulmod(int x,int y,int mod)

{ 

int ans = 0;

__asm__ 

( 

"movl %1,%%eax\n" 

"imull %2\n" 

"idivl %3\n" 



:"=d"(ans) 

:"m"(x),"m"(y),"m"(mod) 

:"%eax" 

); 

return ans; 

}
void dfs(int u, int fa) {

	vector<int> seq;
	
	size[u] = 1;
	for (vector<int> :: iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
		if (*it == fa) continue;
		seq.push_back(*it);
		dfs(*it, u);
		size[u] += size[*it];
	}
//	sort(seq.begin(), seq.end());
	int tot = seq.size();
	
	for (int i = 0; i <= tot; ++i)
	for (int j = 0; j <= size[u]; ++j) {
		g[i][j] = sumg[i][j] = 0;
	}
	
	g[0][0] = 1;
	
	int cursize = 0;
	
	for (int i = 0; i < tot; ++i) {
		
		for (int x = 0; x <= cursize; ++x) {
			sumg[i][x] = (x ? sumg[i][x-1] : 0) + g[i][x];
			sumg[i][x] %= mod;
		}		
		
		int v = seq[i];
		
		add(g[i+1][0], mulmod(mulmod(g[i][0], f[v][0], mod), C[cursize+size[v]][size[v]], mod));
		
		for (int k = 1; k <= size[v]; ++k) {
			
			for (int x = 0; x <= cursize; ++x) {
				int c = C[size[v]-k+cursize-x][size[v]-k];
				c = mulmod(c, C[k-1+x][x], mod);
				c = mulmod(c, f[v][k], mod);
				add(g[i+1][k+x], mulmod(sumg[i][x], c, mod));
			}
		}
		for (int j = 1; j <= cursize; ++j) {
			for (int x = 0; x <= size[v]; ++x) {
				int c = C[size[v]-x+cursize-j][cursize-j];
				c = mulmod(c, C[j-1+x][x], mod);
				c = mulmod(c, g[i][j], mod);
//				c = (LL) c * C[j-1+x][x] % mod * g[i][j] % mod;
				add(g[i+1][j+x], mulmod(sumf[v][x], c, mod));
			}
		}
		
		cursize += size[v];
	}

	int sum = 0;
	int sumx = 0;
	
	for (int x = 0; x <= cursize; ++x) {
	
		sum = (sum + g[tot][x]) % mod;
		sumx = (sumx + mulmod(g[tot][x], x, mod)) % mod;
		f[u][x+1] = sum;
//		for (int y = 1; y <= x; ++y) add(f[u][0], g[tot][x]);
	//	for (int y = x; y <= cursize; ++y) add(f[u][y+1], g[tot][x]);
	
	}
	f[u][0] = sumx;
	for (int x = 0; x <= size[u]; ++x) {
		sumf[u][x] = (x ? sumf[u][x-1] : 0) + f[u][x];
		sumf[u][x] %= mod;
	}
	
}

int main(void) {

	for (int i = 0; i <= 200; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		int n = 0; scanf("%d", &n);
		
		for (int i = 1; i <= n; ++i) edges[i].clear();
		
		for (int i = 1; i < n; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
	
		int ans = 0;
	
		for (int root = 1; root <= n; ++root) {
		
			memset(f, 0, sizeof f);
			memset(sumf, 0, sizeof sumf);
		
		//	for (int i = 1; i <= n; ++i)
		//	for (int j = 0; j <= n; ++j) f[i][j] = sumf[i][j] = 0;
		
			dfs(root, -1);
			for (int x = 1; x <= n; ++x) ans = (ans + f[root][x]) % mod;
		
		}
		printf("%d\n", ans);
	}


	return 0;
}
