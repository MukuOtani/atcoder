S = input()
T = input()
if S == T:
    print('Yes')
    exit()

for i in range(len(S)):
    S = S[1:]+S[0]
    if S == T:
        print('Yes')
        exit()
print('No')
