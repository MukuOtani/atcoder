N, K = map(int, input().split())
x = list(map(int, input().split()))
ans = 10**9
for i in range(N-K+1):
    l = x[i]
    r = x[i+K-1]
    sec1 = abs(l) + abs(r-l)
    sec2 = abs(r) + abs(l-r)
    ans = min(ans, sec1, sec2)
print(ans)
