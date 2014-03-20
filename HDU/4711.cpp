#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

long double f[1024][128];
long double g[128][128];
int c[1024][128];
long double wt[128][128];
int lmt[1024];
double t;
int n,m,w;
int T;
int ans[1024];

int main()
{
    //freopen("in","r",stdin);
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(c,255,sizeof(c));
        scanf("%d%d%d",&n,&m,&w);
        for (int i=1; i<=n; i++) scanf("%d",lmt+i);
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
            {
                scanf("%lf",&t);
                g[i][j]=t;
            }
        for (int i=0; i<m; i++)
            for (int j=0; j<w; j++)
            {
                scanf("%lf",&t);
                wt[i][j]=t;
            }
        for (int i=0; i<m; i++) f[n][i]=wt[i][lmt[n]];
        for (int i=n-1; i>=0; i--)
            for (int j=0; j<m; j++)
            {
                f[i][j]=0;
                long double sf=1;
                if (i!=0) sf=wt[j][lmt[i]];
                for (int k=0; k<m; k++)
                    if (f[i+1][k]*g[j][k]*sf>f[i][j])
                    {
                        f[i][j]=f[i+1][k]*g[j][k]*sf;
                        c[i][j]=k;
                    }
            }
        for (int i=0; i<n; i++)
            ans[i+1]=c[i][ans[i]];
        if (f[0][0]==0)
            memset(ans,0,sizeof(ans));
        printf("%d",ans[1]);
        for (int i=2; i<=n; i++) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
// hehe ~
