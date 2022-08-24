S = input()
K = int(input())

mark = 0
cnt = 0
for i in range(len(S)):
    if S[i] != '1':
        print(S[i])
        exit()
    else:
        cnt += 1
        if K == cnt:
            print('1')
            exit()
