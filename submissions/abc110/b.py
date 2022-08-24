from sys import stdin
N, M, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

xmax = max(x)
ymin = min(y)

if X <= Y:
    for Z in range(X+1,Y+1,1):
        if xmax < Z <= ymin:
            print('No War')
            exit()
    print('War')
else:
    print('War')
