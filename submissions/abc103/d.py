from sys import stdin
N, M = map(int, input().split())
A = []
for _ in range(M):
    A.append([int(x) for x in stdin.readline().rstrip().split()])

A.sort(key=lambda x: x[1])
l = 0
ans = 0
for i in range(M):
    if l < A[i][0]:
        ans += 1
        l = A[i][1] - 1
    else:
        pass
print(ans)
