flag = 0
N = int(input())
c = input().split()
for i in range(0,N):
  if c[i] == 'Y':
    flag = 1
if flag:
  print('Four')
else:
  print('Three')
