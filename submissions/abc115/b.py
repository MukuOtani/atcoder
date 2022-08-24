N = int(input())
p = []
for _ in range(N):
    p.append(int(input()))
print(int(sum(p)-max(p)/2))
