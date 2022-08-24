from sys import stdin
import math
N, K = map(int, input().split())
a = [int(x) for x in stdin.readline().rstrip().split()]

N = N - K
cnt = 1

cnt += math.ceil(N/(K-1))
print(cnt)
