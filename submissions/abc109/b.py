N = int(input())
W = []
for _ in range(N):
    W.append(input())
D = []
for i in range(N):
    if W[i] in D:
        print('No')
        exit()
    else:
        if i == 0:
            pass
        else:
            if D[-1][-1] != W[i][0]:
                print('No')
                exit()
        D.append(W[i])
print('Yes')
