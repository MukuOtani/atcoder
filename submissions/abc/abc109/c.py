N, X = map(int, input().split())
x = list(map(int, input().split()))

def gcd(m, n):
    x = max(m, n)
    y = min(m, n)
    # if x%y:
    #     while x%y:
    #         z = x%y
    #         x, y = y, x
    #     else:
    #         return z
    # else:
    #     return y
    if y == 0:
        return x
    else:
        return gcd(y, x%y)


x.append(X)
x.sort()
# print(x)
# d = []
# for i in range(N):
#     d.append(x[i+1]-x[i])
# print(d)
for i in range(N):
    if i == 0:
        c = x[i+1]-x[i]
    else:
        c = gcd(x[i+1]-x[i], c)
print(c)
