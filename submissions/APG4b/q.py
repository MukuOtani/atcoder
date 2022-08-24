A, op, B = input().split()
a = int(A)
b = int(B)
if op == '+':
  ans = a + b
elif op == '-':
  ans = a - b
elif op == '*':
  ans = a * b
elif op == '/':
  if b == 0:
    ans = 'error'
  else:
    ans = int(a / b)
else:
  ans = 'error'
print(ans)
