#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define lch(n) ((n)<<1)
#define rch(n) (((n)<<1)+1)
#define fi first
#define se second
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double, double> Point;

const int MaxN = 105;
//================= 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
const int d[10] = { 0, 1, 2, 0, 3, 4, 5, 6, 0, 7 };
int a[MaxN];
char str[MaxN];
int main() {
    //freopen("in","r",stdin);
    
    for (scanf("%s\n",str); ; scanf("%s\n",str)) {
        if (str[0] == '0') break;
        int n = strlen(str);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = ans * 8 + d[str[i]-'0'];
        }
        printf("%s: %d\n",str,ans);
    }
    return 0;
}
         



