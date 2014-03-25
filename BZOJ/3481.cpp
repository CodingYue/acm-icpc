// File Name: 3481.cpp
// Author: YangYue
// Created Time: Fri Mar 21 22:27:44 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const int mod = (int)1e9 + 7;
// Always call "IsPrime" unless you know what are you doing
LL fpow(LL a, int t, int mod) {
	LL res = 1;
	a %= mod;
	for (; t; t >>= 1, a = a * a % mod)
		if (t & 1) res = res * a % mod;
	return res;
}
LL mulmod(LL x, LL y, LL z) {
	return (x * y - (LL) (x / (long double) z * y + 1e-3) * z + z) % z;
	
}
LL powmod(LL a, LL t, LL n) {
	LL res = 1;
	for (; t; t >>= 1, a = mulmod(a, a, n))
		if (t & 1) res = mulmod(res, a, n);
	return res;
}
LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int MillerRabin(LL a,LL n)
{
	if(n == 2) return 1;
	if(n == 1 || (n & 1) == 0) return 0;
	LL d = n-1;
	while((d & 1) == 0) d >>= 1;
	LL t = powmod(a,d,n);
	while(d != n-1 && t != 1 && t != n-1)
	{
		t = mulmod(t,t,n);
		d <<= 1;
	}
	return (t == n-1) || ((d & 1) == 1);
}

int LPrimes[] = {2,3,5,7,11,13,17,19,23};
int IsPrime(LL n)
{
	int result = 1;
	for(int i = 0;i < sizeof(LPrimes)/sizeof(int);i++)
	{
		if(LPrimes[i] >= n) break;
		result &= MillerRabin(LPrimes[i],n);
		if(!result) return result;
	}
	return result;
}
LL PollardRho(LL n,int c)
{
	LL x = 2;
	LL y = 2;
	LL d = 1;
	while(d == 1)
	{
		x = (mulmod(x,x,n)+c)%n;
		y = (mulmod(y,y,n)+c)%n;
		y = (mulmod(y,y,n)+c)%n;

		if(x > y) d = gcd(x-y,n);
		else d = gcd(y-x,n);
	}
	return d;
}

// DO NOT CALL THIS WITH A PRIME!
LL Factorize(LL n)
{
	LL d = n;
	while(d == n) d = PollardRho(n,rand()+1);
	return d;
}

LL dv[111111];
int dvcnt = 0;

// call sort if sorted results needed.
LL FLLFactorize(LL n)
{
	if(n%2 == 0)
	{
		dv[dvcnt++] = 2;
		while(n%2 == 0) n /= 2;
		return FLLFactorize(n);
	}
	LL t = 0;
	while(n != 1 && !IsPrime(n))
	{
		t = Factorize(n);
		int cdvc = dvcnt;
		if(!IsPrime(t)) FLLFactorize(t);
		else dv[dvcnt++] = t;
		for(int i = cdvc;i < dvcnt;i++)
		{
			while(n % dv[i] == 0) n /= dv[i];
		}
	}
	if(n != 1) dv[dvcnt++] = n;
	return 0;
}
vector<PLI> read(int n) {
	LL tmpseq[11];
	memset(tmpseq, 0, sizeof tmpseq);
	set<LL> SET;
	vector<PLI> ret;
	for (int i = 0; i < n; ++i) {
		cin >> tmpseq[i];
		if (tmpseq[i] == 0) return ret;
		dvcnt = 0;
		FLLFactorize(tmpseq[i]);
		for (int k = 0; k < dvcnt; ++k) SET.insert(dv[k]);
	}
	for (set<LL> :: iterator it = SET.begin(); it != SET.end(); ++it) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			LL tmp = tmpseq[i];
			while (tmp % *it == 0) ++cnt, tmp /= *it;
		}
		ret.push_back(make_pair(*it, cnt));
	}
	return ret;
}
vector<PLI> getgcd(const vector<PLI> &P, const vector<PLI> &Q) {
	int i = 0, j = 0;
	if (Q.size() == 0) return P;
	vector<PLI> ret;
	while (i < P.size() && j < Q.size()) {
		if (P[i].first == Q[j].first) {
			ret.push_back(make_pair(P[i].first, min(P[i].second, Q[j].second)));
			++i;
			++j;
		} else 
		if (P[i].first < Q[j].first) ++i;
		else ++j;
	}
	if (ret.size() == 0) 
		ret.push_back(make_pair(0, 0));
	return ret;
}
LL func(const LL &P, int d, int t) {
	LL res = 1;
	d -= t;
	if (d == 0) return 1;
	for (int j = 0; j < d - 1; ++j) res = P % mod * res % mod;
	res = (P - 1) % mod * res % mod;
	return res;
}
bool used[11111];
int main() {
	
	freopen("in","r",stdin);
	int n; cin >> n;
	vector<PLI> P, Q, M;
	P = read(n);
	Q = read(n);
	/*
	printf("P size = %d\n", (int) P.size());
	for (int i = 0; i < P.size(); ++i) printf("%lld^%d ", P[i].first, P[i].second);
	printf("\n");
*///
	/*
	int PP = 7 * 2 * 11;
	int QQ = 7 * 2 * 11 * 55;
	int cnt = 0;
	for (int i = 0; i < PP; ++i)
	for (int j = 0; j < PP; ++j) if (i * j % PP == QQ % PP) ++cnt;
	cout << cnt << endl;
	cnt = 0;
	for (int x = 0; x < PP; ++x) if (QQ % __gcd(x, PP) == 0) 
		cnt += __gcd(x, PP);
	cout << cnt << endl;
	*/
	M = getgcd(P, Q);
	LL res = 1;
	for (int i = 0; i < M.size(); ++i) {
		int find = -1;
		for (int j = 0; j < P.size(); ++j) if (M[i].first == P[j].first) {
			find = j;
			used[j] = 1;
			break;
		}
		int alpha = 0;
		if (find != -1) alpha = P[find].second;
		LL tmp = 0, now = 1;
		for (int j = 0; j <= M[i].second; ++j) {
			tmp = (tmp + func(M[i].first, alpha, j) * now % mod) % mod;
			now = M[i].first % mod * now % mod;
		}
		res = res * tmp % mod;
	}
	for (int i = 0; i < P.size(); ++i) if (!used[i]) 
		res = res * func(P[i].first, P[i].second, 0) % mod;
	cout << res << endl;
	return 0;
}

