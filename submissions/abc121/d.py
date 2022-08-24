A, B = map(int, input().split())

def XOR(A):
    # 0‚©‚çA‚Ü‚Å‚Ì”r‘¼“I˜_—˜a‚ğ‹‚ß‚é
    if A%4 == 0:
        return A
    elif A%4 == 2:
        return A+1
    elif A%4 == 1:
        return 1
    else:
        return 0

fA = XOR(A-1)
fB = XOR(B)
print(fB^fA)
