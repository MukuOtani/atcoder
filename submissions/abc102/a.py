import statistics
import math

N = int(input())
a = input().split()
ans = 0
for i in range(0,N):
	a[i] = int(a[i])-i
med = int(statistics.median(a))
for i in range(0,N):
	ans += abs(a[i]-med)
print(int(ans))
