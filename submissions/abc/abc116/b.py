l = []
l.append(int(input()))
i = 0
key = 1
while key:
  if l[i]%2:
    l.append(3*l[i]+1)
  else:
    l.append(l[i]/2)
  i += 1
  for j in range(i-1):
    if l[j] == l[i]:
      key = 0
      print(i+1)
      break
