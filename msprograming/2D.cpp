#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int x[111];
int y[111];
int z[111];

int N = 0;

double calc(double B,double C)
{
	double ans = 0.0;
	for(int i = 0;i < N;i++)
	{
		double upper = (1.0*x[i]+B*y[i]+C*z[i]);
		ans += upper*upper/(1+B*B+C*C);
	}
	return ans;
}

double findB(double C)
{
	double l = -1e6;
	double r = 1e6;
	while(r-l > 1e-9)
	{
		double sep = (r-l)/3.;
		double lmid = l+sep;
		double rmid = r-sep;
		if(calc(lmid,C) < calc(rmid,C)) r = rmid;
		else l = lmid;
	}
	return calc(l,C);
}

double findB_ret(double C)
{
	double l = -1e6;
	double r = 1e6;
	while(r-l > 1e-9)
	{
		double sep = (r-l)/3.;
		double lmid = l+sep;
		double rmid = r-sep;
		if(calc(lmid,C) < calc(rmid,C)) r = rmid;
		else l = lmid;
	}
	return l;
}

double findC()
{
	double l = -1e6;
	double r = 1e6;
	while(r-l > 1e-9)
	{
		double sep = (r-l)/3.;
		double lmid = l+sep;
		double rmid = r-sep;
		if(findB(lmid) < findB(rmid)) r = rmid;
		else l = lmid;
	}
	return l;
}

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case %d: ",++TK);
		scanf("%d",&N);
		for(int i = 0;i < N;i++) scanf("%d %d %d",&x[i],&y[i],&z[i]);
		double C = findC();
		double B = findB_ret(C);
		printf("%.8f %.8f %.8f\n",1.0,B,C);
		//printf("tenans: %.8f\n",calc(B,C));
	}
	while(getchar() != EOF);
	return 0;
}

