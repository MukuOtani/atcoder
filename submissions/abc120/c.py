S = list(input())
a = 0
b = 0
for i in range(len(S)):
  if int(S[i]):
    a += 1
  else:
    b += 1
if a < b:
  print(a*2)
else:
  print(b*2)
