from sys import stdin
N, T = [int(x) for x in stdin.readline().rstrip().split()]
d = 1001
for i in range(N):
  l = list(map(int, input().split()))
  if l[1] <= T:
    if l[0] < d:
      d = l[0]
if d < 1001:
  print(d)
else:
  print('TLE')
