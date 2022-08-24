N, K = map(int, input().split())
cnt = 0
cnt2 = 0
for i in range(1,N+1):
    if i%K == 0:
        cnt += 1
if K%2 == 0:
    for i in range(1,N+1):
        if i%K == K/2:
            cnt2 += 1
ans = cnt**3 + cnt2**3
print(ans)
