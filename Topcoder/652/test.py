n = 102
def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)
ans=1
for i in range(1, n+1):
    ans = ans * i / gcd(ans, i)

print ans % (10**9+7)

