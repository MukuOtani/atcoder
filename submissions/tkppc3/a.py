c1, A = input().split()
c2, B = input().split()
def to_int(c,N):
	if c == 'W':
		n = int(N)*(-1)
	else:
		n = int(N)
	return n
a = to_int(c1,A)
b = to_int(c2,B)
print(int((abs(a-b)/15)))
