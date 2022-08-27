N = int(input())
sum = 0
for i in range (N):
  X = input().split()
  if X[1] == 'JPY':
    sum += float(X[0])
  else:
  	sum += float(X[0])*380000
print(sum)
