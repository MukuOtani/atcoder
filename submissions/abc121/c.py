N, M = map(int, input().split())

A = []
for _ in range(N):
    A.append(list(map(int, input().split())))

A.sort(key=lambda x: x[0])
ans = 0
num = 0
i = 0
while True:
    if M - num <= A[i][1]:
        ans += A[i][0] * (M-num)
        num = M
    else:
        ans += A[i][0] * A[i][1]
        num += A[i][1]
        i += 1
    if num == M:
        print(ans)
        break
