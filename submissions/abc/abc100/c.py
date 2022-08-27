from sys import stdin
N = int(input())
a = [int(x) for x in stdin.readline().rstrip().split()]
ans = 0
for i in range(N):
    while a[i]%2 != 1:
        a[i] = a[i]/2
        ans += 1
print(ans)
