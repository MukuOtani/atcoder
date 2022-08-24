N = input()
S = 0
for i in range(len(N)):
    S += int(N[i])
print('YNeos'[int(N)%S!=0::2])
