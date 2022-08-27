from sys import stdin
import numpy as np
N = int(input())
T, A = [int(x) for x in stdin.readline().rstrip().split()]
H = list(map(int, input().split()))
d = []

for i in range(len(H)):
    d.append(abs(T-H[i]*0.006-A))
print(np.argmin(d)+1)
