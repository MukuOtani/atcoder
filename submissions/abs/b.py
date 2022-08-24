from sys import stdin
N = int(input())
l = list(map(int, input().split()))
ans = 0
i = 0
while True:
    if l[i]%2 == 0:
        l[i] = l[i]/2
        i += 1
        if i == N-1:
            ans += 1
            i = 0
        else:
            pass
    else:
      break


print(ans)
