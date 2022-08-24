n = input()
a,b,c = [int(n[i]) for i in range(len(n))]

if a > b:
  print(a*111)
elif a == b:
  if b >= c:
    print(a*111)
  else:
    print((a+1)*111)
else:
  print((a+1)*111)
  
