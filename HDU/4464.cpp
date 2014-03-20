#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef unsigned long long ULL;
#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define fi first
#define se second
#define lowbit(i) (i&-i)


char s[200];
int n;
int main() {
    int cases = 0;
    while (scanf("%d\n",&n) != EOF) {
        int Max = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s",s);
            int len = strlen(s), tmp = 0;
            for (int j = 0; j < len; ++j)
                tmp += s[j];
            Max = max(Max, tmp);
        }
        printf("Case %d: %d\n",++cases, Max);
    }
    return 0;
}