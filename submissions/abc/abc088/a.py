N = int(input())
A = int(input())
num = int(N/500)
res = N - 500*num
if A < res:
  print('No')
else:
  print('Yes')
