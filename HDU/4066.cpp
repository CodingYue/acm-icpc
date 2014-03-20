#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double ans[1505];
int main(){
    ans[1]=1.0;
    double x=1.0;
    for (int i=2;i<1505;i++){
        if (i%2==0) x*=double(i-1.0)/double(i+0.0);
        ans[i]=ans[i-1]+x;
    }
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;i++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %0.6lf\n",i,ans[n]);
    }
    return 0;
}