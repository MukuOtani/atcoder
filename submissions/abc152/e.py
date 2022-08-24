def gcd(a,b):
  while b:a,b=b,a%b
  return a
def lcm(a,b):
  return a*b//gcd(a,b)
mod = 10**9+7

n = int(input())
a = list(map(int,input().split()))
l = 1
for i in range(n):
    l = lcm(l,a[i])
l %= mod

ans=0
for i in range(n):
    ans += l*pow(a[i],mod-2,mod)
    ans %= mod
print(ans)
