from sys import stdin
a,b,c = [int(x) for x in stdin.readline().rstrip().split()]
if c > a+b+1:
  print(a+2*b+1)
else:
  print(b+c)
