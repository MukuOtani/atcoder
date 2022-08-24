from sys import stdin
N = int(input())
A = [int(x) for x in stdin.readline().rstrip().split()]

ans = 0
for i in range(N):
    ans += A[i]-1

print(ans)
