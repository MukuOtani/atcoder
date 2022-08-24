N = int(input())
s = []
if N == 0:
    print(N)
    exit()
while N:
    s.append(abs(N)%2)
    N -= 1
    N //= -2
for i in range(1,len(s)+1):
    print(s[-i], end='')
