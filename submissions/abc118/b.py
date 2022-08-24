from sys import stdin
N, M = [int(x) for x in stdin.readline().rstrip().split()]
l = []
m = []
for i in range(N):
    l.append(stdin.readline().rstrip().split())
    l[i].pop(0)
k = l[N-1]
for i in range(N-1):
    k = set(k)&set(l[i])
print(len(k))
