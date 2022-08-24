N = int(input())
A = int(input())
ans = []
for i in range(0,N):
	op, B = input().split()
	B = int(B)
	if op == '+':
		A = A+B
		ans.append('{}:{}'.format(i+1, A))
	elif op == '-':
		A = A-B
		ans.append('{}:{}'.format(i+1, A))
	elif op == '*':
		A = A*B
		ans.append('{}:{}'.format(i+1, A))
	elif op == '/':
		if B == 0:
			ans.append('error')
			break
		else:
			A = int(A/B)
			ans.append('{}:{}'.format(i+1, A))
	else:
		ans.append('error')
		break
for i in range(0, len(ans)):
	print(ans[i])
