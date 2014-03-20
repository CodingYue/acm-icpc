#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MaxN = 262145;
const int P = 1000003;
int A[MaxN], B[MaxN], C[MaxN];
namespace fft {
    const int P = 1000003;
    const int N = 100010;
    const int N1 = 262144;
    const int P1 = 998244353;
    const int P2 = 995622913;
    const int E1 = 996173970;
    const int E2 = 88560779;
    const int F1 = 121392023;
    const int F2 = 840835547;
    const int I1 = 998240545;
    const int I2 = 995619115;
    const LL M1 = 397550359381069386LL;
    const LL M2 = 596324591238590904LL;
    const LL MM = 993874950619660289LL;
    LL mul(LL x, LL y, LL z) {
        return (x * y - (LL) (x / (long double) z * y + 1e-3) * z + z) % z;
    }
    int crt(int x1, int x2) {
        return (mul(M1, x1, MM) + mul(M2, x2, MM)) % MM % P;
    }
    void fft(int *A, int PM, int PW) {
        for (int m = N1, h; h = m / 2, m >= 2; PW = (LL) PW * PW % PM, m = h) {
            for (int i = 0, w = 1; i < h; ++i, w = (LL) w * PW % PM)
            for (int j = i; j < N1; j += m) {
                int k = j + h, x = (A[j] - A[k] + PM) % PM;
                A[j] += A[k]; A[j] %= PM;
                A[k] = (LL) w * x % PM;
            }
        }
        for (int i = 0, j = 1; j < N1 - 1; ++j) {
            for (int k = N1 / 2; k > (i^=k); k /= 2);
            if (j < i) swap(A[i], A[j]);
        }
    }
    int A1[MaxN], B1[MaxN], C1[MaxN];
    void mul(int *A, int *B, int *C, int n) {
        memset(C, 0, sizeof(*C)*N1);
        memcpy(A1, A, sizeof(*A)*N1);
        memcpy(B1, B, sizeof(*B)*N1);
        
        fft(A1, P1, E1);
        fft(B1, P1, E1);
        for (int i = 0; i < N1; ++i) C1[i] = (LL) A1[i] * B1[i] % P1;
        fft(C1, P1, F1);
        for (int i = 0; i < N1; ++i) C1[i] = (LL) C1[i] * I1 % P1;
        
        fft(A, P2, E2);
        fft(B, P2, E2);
        for (int i = 0; i < N1; ++i) C[i] = (LL) A[i] * B[i] % P2;
        fft(C, P2, F2);
        for (int i = 0; i < N1; ++i) C[i] = (LL) C[i] * I2 % P2;
        for (int i = 0; i < N1; ++i) C[i] = crt(C1[i], C[i]);
        for (int i = n; i < N1; ++i) C[i] = 0;
    }
}
int fpow(int a, int t, int mod) {
    int res = 1;
    for (; t; t >>= 1, a = (LL) a * a % mod) {
        if (t & 1) res = (LL) res * a % mod;
    }
    return res;
}
int fac[P], inv[P], a[MaxN], pd[MaxN], pc[MaxN], pc2[MaxN], pb[MaxN]; 
int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    fac[0] = 1;
    inv[1] = 1;
    for (int i = 1; i < P; ++i) {
        fac[i] = (LL) fac[i-1] * i % P;
    }
    for (int i = 2; i < P; ++i) {
        inv[i] = (LL) P / i * (P - inv[P % i]) % P;
    }

    int n, b, c, d;
    
    scanf("%d%d%d%d", &n, &b, &c, &d);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    pd[0] = 1; for (int i = 1; i < n; ++i) pd[i] = (LL) pd[i-1] * d % P;
    for (int i = 0; i < n; ++i) A[i] = (LL) a[n-i-1] * fac[n-i-1] % P;
    for (int i = 0; i < n; ++i) B[i] = (LL) inv[fac[i]] * pd[i] % P;

    //for (int i = 0; i < n; ++i) printf("%d ",A[i]); printf("\n");
    //for (int i = 0; i < n; ++i) printf("%d ",B[i]); printf("\n");
    
    fft :: mul(A, B, C, n);
    //for (int i = 0; i < n; ++i) printf("%d ", C[i]); printf("\n");

    memcpy(A, C, sizeof C); reverse(A, A + n);
    pb[0] = 1; for (int i = 1; i < n; ++i) pb[i] = (LL) pb[i-1] * b % P;
    for (int i = 0; i < n; ++i) A[i] = (LL)A[i] * pb[i] % P * inv[fac[i]] % P;
    pc2[0] = 1; int c2 = (LL) c * c % P;
    for (int i = 1, s = c; i < n; ++i) 
        pc2[i] = (LL) pc2[i-1] * s % P, s = (LL) s * c2 % P;
    for (int i = 0; i < n; ++i) A[i] = (LL) A[i] * pc2[i] % P;
    memset(B, 0, sizeof B);
    B[0] = 1;
    for (int i = 1; i < n; ++i) B[i] = inv[pc2[i]], B[MaxN - 1 - i] = inv[pc2[i]];

    //for (int i = 0; i < n; ++i) printf("%d ",A[i]); printf("\n");
    //for (int i = 0; i < n; ++i) printf("%d ",B[i]); printf("\n");
    //for (int i = 1; i < n; ++i) printf("%d ", B[MaxN - 1 - i]); printf("\n");

    fft :: mul(A, B, C, n);

    //for (int i = 0; i < n; ++i) printf("%d ", C[i]); printf("\n");

    
    for (int i = 0; i < n; ++i) {
        C[i] = (LL) C[i] * pc2[i] % P;
        printf("%d\n", C[i]);
    }
    

    return 0;
}
